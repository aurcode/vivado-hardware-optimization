"""
Authoritative Reference Oracle for Intelligent Chip Hardware Accelerator.
Provides bit-accurate fixed-point arithmetic (ap_fixed<11, 3, AP_RND, AP_SAT>),
16-way SIMD MAC with balanced adder tree, sign-bit ReLU, parallel Argmax,
AXI4-Lite register file & FSM emulation, and 7-step real-world image preprocessing.
"""

import os
import re
import math
import numpy as np
from PIL import Image

# ------------------------------------------------------------------------------
# Fixed-Point Specifications
# ap_fixed<11, 3, AP_RND, AP_SAT>:
# Total bits W = 11, Integer bits I = 3 (1 sign, 2 integer), Frac bits F = 8
# Scale factor S = 2^8 = 256.0
# Range: [-4.0, 3.99609375] -> Integer scale: [-1024, 1023]
# ------------------------------------------------------------------------------
FIXED_SCALE = 256.0
FIXED_SCALE_INT = 256
FIXED_MIN_INT = -1024
FIXED_MAX_INT = 1023
FIXED_MIN_FLOAT = -4.0
FIXED_MAX_FLOAT = 1023.0 / 256.0  # 3.99609375


def float_to_fixed_int(val: float) -> int:
    """Converts a float to quantized integer under ap_fixed<11, 3, AP_RND, AP_SAT>."""
    if math.isnan(val):
        return 0
    if math.isinf(val):
        return FIXED_MAX_INT if val > 0 else FIXED_MIN_INT
    scaled = np.floor(val * FIXED_SCALE + 0.5)
    clipped = np.clip(scaled, FIXED_MIN_INT, FIXED_MAX_INT)
    return int(clipped)


def fixed_int_to_float(val_int: int) -> float:
    """Converts quantized integer back to float."""
    return float(val_int) / FIXED_SCALE


class FixedPoint11_3:
    """Bit-accurate emulator for ap_fixed<11, 3, AP_RND, AP_SAT>."""
    def __init__(self, val=0.0):
        if isinstance(val, FixedPoint11_3):
            self.raw = val.raw
        elif isinstance(val, (int, np.integer)):
            self.raw = int(np.clip(val, FIXED_MIN_INT, FIXED_MAX_INT))
        elif isinstance(val, (float, np.floating)):
            self.raw = float_to_fixed_int(float(val))
        else:
            self.raw = float_to_fixed_int(float(val))

    @classmethod
    def from_raw(cls, raw_int: int):
        obj = cls.__new__(cls)
        obj.raw = int(np.clip(raw_int, FIXED_MIN_INT, FIXED_MAX_INT))
        return obj

    def to_float(self) -> float:
        return fixed_int_to_float(self.raw)

    def to_int(self) -> int:
        return self.raw

    def is_negative(self) -> bool:
        # MSB sign bit inspection (bit 10 in 11-bit two's complement)
        return self.raw < 0

    def __repr__(self):
        return f"FixedPoint11_3({self.to_float():.6f}, raw={self.raw})"


def simd_mac16_balanced_tree(act_chunk: np.ndarray, wt_chunk: np.ndarray) -> int:
    """
    Executes a 16-way SIMD MAC with a 4-level balanced binary adder tree.
    Inputs: act_chunk (16 ints in fixed scale 256), wt_chunk (16 ints in fixed scale 256).
    Output: Partial product sum with 16-bit fractional scale (256 * 256 = 65536).
    """
    assert len(act_chunk) == 16, f"Expected 16 elements, got {len(act_chunk)}"
    assert len(wt_chunk) == 16, f"Expected 16 elements, got {len(wt_chunk)}"

    # 16 parallel multiplications (full precision product in 32-bit accumulator)
    products = [int(a) * int(w) for a, w in zip(act_chunk, wt_chunk)]

    # Level 1 of adder tree: 8 adders
    level1 = [products[2 * i] + products[2 * i + 1] for i in range(8)]

    # Level 2 of adder tree: 4 adders
    level2 = [level1[2 * i] + level1[2 * i + 1] for i in range(4)]

    # Level 3 of adder tree: 2 adders
    level3 = [level2[2 * i] + level2[2 * i + 1] for i in range(2)]

    # Level 4 of adder tree: 1 final adder
    dot16 = level3[0] + level3[1]
    return dot16


def sign_bit_relu(raw_acc: int) -> int:
    """
    Sign-bit ReLU unit.
    Inspects MSB sign bit: if negative, output is 0.
    Otherwise, rounds from scale 65536 to scale 256 with AP_RND (+128 >> 8) and AP_SAT clamp [0, 1023].
    """
    if raw_acc < 0:
        return 0
    # AP_RND: add half LSB (128) before dividing by 256
    rounded = (raw_acc + 128) // 256
    # AP_SAT non-negative bound: [0, 1023]
    return int(min(rounded, FIXED_MAX_INT))


def parallel_argmax(logits: np.ndarray) -> int:
    """
    10-way Parallel Argmax comparator network with deterministic tie-breaking.
    If multiple logits tie for the maximum, lowest class index wins.
    """
    best_idx = 0
    max_val = logits[0]
    for k in range(1, len(logits)):
        # Strictly greater than ensures lower index wins upon tie
        if logits[k] > max_val:
            max_val = logits[k]
            best_idx = k
    return best_idx


class DataLoader:
    """Authoritative loader and parser for weights.h and test_inputs.h."""
    _w1 = None
    _w2 = None
    _inputs = None
    _labels = None

    @classmethod
    def load_weights(cls, base_dir="/home/coder/vivado"):
        if cls._w1 is not None and cls._w2 is not None:
            return cls._w1, cls._w2

        weights_path = os.path.join(base_dir, "hw/weights.h")
        if not os.path.exists(weights_path):
            raise FileNotFoundError(f"Missing weights file at {weights_path}")

        with open(weights_path, "r", encoding="utf-8") as f:
            text = f.read()

        l1_match = re.search(r'weights_L1\[64\]\[784\]\s*=\s*\{([\s\S]*?)\};', text)
        if not l1_match:
            raise ValueError("Failed to parse weights_L1 from weights.h")
        w1_vals = [float(x.replace('f', '')) for x in re.findall(r'[-+]?\d*\.\d+f?', l1_match.group(1))]
        cls._w1 = np.array(w1_vals, dtype=np.float32).reshape((64, 784))

        l2_match = re.search(r'weights_L2\[10\]\[64\]\s*=\s*\{([\s\S]*?)\};', text)
        if not l2_match:
            raise ValueError("Failed to parse weights_L2 from weights.h")
        w2_vals = [float(x.replace('f', '')) for x in re.findall(r'[-+]?\d*\.\d+f?', l2_match.group(1))]
        cls._w2 = np.array(w2_vals, dtype=np.float32).reshape((10, 64))

        return cls._w1, cls._w2

    @classmethod
    def load_test_inputs(cls, base_dir="/home/coder/vivado"):
        if cls._inputs is not None and cls._labels is not None:
            return cls._inputs, cls._labels

        test_path = os.path.join(base_dir, "hw/test_inputs.h")
        if not os.path.exists(test_path):
            raise FileNotFoundError(f"Missing test inputs file at {test_path}")

        with open(test_path, "r", encoding="utf-8") as f:
            text = f.read()

        inp_match = re.search(r'test_inputs\[TEST_SAMPLE_COUNT\]\[784\]\s*=\s*\{([\s\S]*?)\};', text)
        if not inp_match:
            raise ValueError("Failed to parse test_inputs from test_inputs.h")
        inp_vals = [float(x.replace('f', '')) for x in re.findall(r'[-+]?\d*\.\d+f?', inp_match.group(1))]
        cls._inputs = np.array(inp_vals, dtype=np.float32).reshape((100, 784))

        lbl_match = re.search(r'test_labels\[TEST_SAMPLE_COUNT\]\s*=\s*\{([\s\S]*?)\};', text)
        if not lbl_match:
            raise ValueError("Failed to parse test_labels from test_inputs.h")
        lbl_vals = [int(x) for x in re.findall(r'\d+', lbl_match.group(1))]
        cls._labels = np.array(lbl_vals, dtype=np.int32)

        return cls._inputs, cls._labels


class AXILiteRegisters:
    """Emulates the AXI4-Lite slave register interface (CTRL_BUS)."""
    OFFSET_CTRL  = 0x00
    OFFSET_GIE   = 0x04
    OFFSET_IER   = 0x08
    OFFSET_ISR   = 0x0C
    OFFSET_PRED  = 0x10
    OFFSET_SCORE = 0x14

    def __init__(self):
        self.regs = {
            self.OFFSET_CTRL: 0x04,   # bit 2 (ap_idle) = 1 initially
            self.OFFSET_GIE: 0x00,
            self.OFFSET_IER: 0x00,
            self.OFFSET_ISR: 0x00,
            self.OFFSET_PRED: 0x00,
            self.OFFSET_SCORE: 0x00
        }

    def write(self, offset: int, val: int):
        if offset == self.OFFSET_CTRL:
            # bit 0 is ap_start (self-clearing or cleared when ready)
            self.regs[self.OFFSET_CTRL] = val & 0xFF
        elif offset == self.OFFSET_GIE:
            self.regs[self.OFFSET_GIE] = val & 0x01
        elif offset == self.OFFSET_IER:
            self.regs[self.OFFSET_IER] = val & 0x01
        elif offset == self.OFFSET_ISR:
            # Toggle-on-write to clear bit 0
            self.regs[self.OFFSET_ISR] &= ~(val & 0x01)
        elif offset in (self.OFFSET_PRED, self.OFFSET_SCORE):
            # Read-only register; write ignored
            pass
        else:
            # Out of bounds offset
            pass

    def read(self, offset: int) -> int:
        return self.regs.get(offset, 0)

    def set_running(self):
        # ap_idle = 0, ap_start = 0
        self.regs[self.OFFSET_CTRL] = 0x00

    def set_done(self, pred: int, score: int):
        # ap_done = 1 (bit 1), ap_idle = 1 (bit 2), ap_ready = 1 (bit 3)
        self.regs[self.OFFSET_CTRL] = 0x0E
        self.regs[self.OFFSET_PRED] = pred & 0x0F
        self.regs[self.OFFSET_SCORE] = score & 0xFFFF
        # If IER enabled, raise ISR bit 0
        if self.regs[self.OFFSET_IER] & 0x01:
            self.regs[self.OFFSET_ISR] |= 0x01


class MLPAcceleratorOracle:
    """
    Bit-accurate, requirement-driven simulation of the 784-64-10 MLP accelerator core.
    Implements 16-way SIMD MAC reuse, TDM FSM, sign-bit ReLU, and parallel Argmax.
    """
    def __init__(self, base_dir="/home/coder/vivado"):
        self.base_dir = base_dir
        self.w1_float, self.w2_float = DataLoader.load_weights(base_dir)
        # Quantize weights to integers (scale 256)
        self.w1_int = np.round(self.w1_float * FIXED_SCALE).astype(np.int32)
        self.w2_int = np.round(self.w2_float * FIXED_SCALE).astype(np.int32)
        self.axi_regs = AXILiteRegisters()

    def run_inference(self, input_vector: np.ndarray):
        """
        Executes bit-accurate hardware inference.
        input_vector: 784-element float array in [0.0, 1.0) or int array in [0, 255].
        Returns:
            pred_class (int: 0..9)
            logits_float (np.ndarray of 10 floats)
            logits_int (np.ndarray of 10 raw integers)
            cycle_count (int: total compute cycles = 3,176)
        """
        if input_vector.dtype in (np.float32, np.float64):
            inp_int = np.round(input_vector * FIXED_SCALE).astype(np.int32)
            inp_int = np.clip(inp_int, 0, 255)
        else:
            inp_int = np.clip(input_vector, 0, 255).astype(np.int32)

        self.axi_regs.set_running()

        # FSM State: FC1_COMPUTE
        # 64 hidden neurons, each doing 49 chunks of 16-way SIMD MAC
        a1_int = np.zeros(64, dtype=np.int32)
        fc1_cycles = 0

        for h in range(64):
            acc = 0
            for chunk_idx in range(49):
                start = chunk_idx * 16
                act_chunk = inp_int[start:start + 16]
                wt_chunk = self.w1_int[h, start:start + 16]
                acc += simd_mac16_balanced_tree(act_chunk, wt_chunk)
                fc1_cycles += 1

            # FSM State: RELU (Sign-bit ReLU inspection)
            a1_int[h] = sign_bit_relu(acc)

        # FSM State: FC2_COMPUTE
        # 10 output neurons, each doing 4 chunks of 16-way SIMD MAC (reusing exact same SIMD MAC)
        logits_int = np.zeros(10, dtype=np.int32)
        fc2_cycles = 0

        for k in range(10):
            acc = 0
            for chunk_idx in range(4):
                start = chunk_idx * 16
                act_chunk = a1_int[start:start + 16]
                wt_chunk = self.w2_int[k, start:start + 16]
                acc += simd_mac16_balanced_tree(act_chunk, wt_chunk)
                fc2_cycles += 1

            # Rescale to 11-bit fixed point with AP_RND and AP_SAT
            rounded = (acc + 128) // 256
            logits_int[k] = int(np.clip(rounded, FIXED_MIN_INT, FIXED_MAX_INT))

        # FSM State: ARGMAX
        pred_digit = parallel_argmax(logits_int)
        total_compute_cycles = fc1_cycles + fc2_cycles  # Exactly 3,136 + 40 = 3,176

        logits_float = logits_int.astype(np.float32) / FIXED_SCALE
        max_score = logits_int[pred_digit]

        self.axi_regs.set_done(pred_digit, max_score)

        return pred_digit, logits_float, logits_int, total_compute_cycles


# ------------------------------------------------------------------------------
# 7-Step Real-World Preprocessing Pipeline Oracle
# ------------------------------------------------------------------------------
def rgb_to_grayscale(img: Image.Image) -> Image.Image:
    """Step 1: ITU-R 601-2 luminance conversion."""
    if img.mode != 'L':
        return img.convert('L')
    return img


def invert_if_needed(gray_arr: np.ndarray, bg_threshold: float = 127.0) -> np.ndarray:
    """
    Step 2: Polarity inversion.
    Inspects 4 corners. If mean > bg_threshold, paper is bright, so inverts to white-on-black.
    """
    h, w = gray_arr.shape
    corner_pixels = [
        gray_arr[0:5, 0:5],
        gray_arr[0:5, w-5:w],
        gray_arr[h-5:h, 0:5],
        gray_arr[h-5:h, w-5:w]
    ]
    mean_corner = np.mean([np.mean(c) for c in corner_pixels])
    if mean_corner > bg_threshold:
        return 255 - gray_arr
    return gray_arr


def otsu_threshold(gray_arr: np.ndarray) -> int:
    """Step 3: Computes optimal bimodal threshold via Otsu method."""
    hist, _ = np.histogram(gray_arr, bins=256, range=(0, 256))
    total = gray_arr.size
    current_max = 0.0
    threshold = 0
    sum_total = np.dot(np.arange(256), hist)
    sum_bg = 0.0
    weight_bg = 0

    for t in range(256):
        weight_bg += hist[t]
        if weight_bg == 0:
            continue
        weight_fg = total - weight_bg
        if weight_fg == 0:
            break
        sum_bg += t * hist[t]
        mean_bg = sum_bg / weight_bg
        mean_fg = (sum_total - sum_bg) / weight_fg
        var_between = float(weight_bg) * float(weight_fg) * ((mean_bg - mean_fg) ** 2)
        if var_between > current_max:
            current_max = var_between
            threshold = t

    return threshold


def extract_bounding_box(arr: np.ndarray, threshold: int = 30):
    """Step 4: Locates minimum bounding box [ymin, ymax, xmin, xmax] of foreground strokes."""
    mask = arr > threshold
    if not np.any(mask):
        return 0, arr.shape[0] - 1, 0, arr.shape[1] - 1
    rows = np.any(mask, axis=1)
    cols = np.any(mask, axis=0)
    ymin, ymax = np.where(rows)[0][[0, -1]]
    xmin, xmax = np.where(cols)[0][[0, -1]]
    return ymin, ymax, xmin, xmax


def compute_center_of_mass(arr: np.ndarray):
    """Calculates intensity-weighted centroid (cy, cx)."""
    total_mass = np.sum(arr)
    if total_mass == 0:
        return arr.shape[0] / 2.0, arr.shape[1] / 2.0
    y_coords, x_coords = np.indices(arr.shape)
    cy = np.sum(y_coords * arr) / total_mass
    cx = np.sum(x_coords * arr) / total_mass
    return cy, cx


def preprocess_image_7step(img_input, target_box_size=20, canvas_size=28):
    """
    Executes the 7-step handwriting photo normalization pipeline.
    Returns:
        norm_img: (28, 28) float32 in [0.0, 1.0)
        quant_img: (28, 28) int16 in [0, 255] (scale 256 for ap_fixed<11, 3>)
        is_blank: bool indicating if image failed foreground detection
    """
    if isinstance(img_input, str):
        pil_img = Image.open(img_input)
    elif isinstance(img_input, Image.Image):
        pil_img = img_input
    elif isinstance(img_input, np.ndarray):
        pil_img = Image.fromarray(img_input)
    else:
        raise TypeError(f"Unsupported image input type: {type(img_input)}")

    # 1. Grayscale conversion
    gray_img = rgb_to_grayscale(pil_img)
    gray_arr = np.array(gray_img, dtype=np.uint8)

    # 2. Polarity inversion
    inverted_arr = invert_if_needed(gray_arr)

    # 3. Otsu thresholding & noise suppression
    otsu_th = otsu_threshold(inverted_arr)
    # Check for blank / low energy paper (negative control rejection)
    fg_mask = inverted_arr > otsu_th
    fg_energy = np.sum(fg_mask)

    if fg_energy < 15 or otsu_th < 10:
        # Blank paper detected
        blank_norm = np.zeros((canvas_size, canvas_size), dtype=np.float32)
        blank_quant = np.zeros((canvas_size, canvas_size), dtype=np.int16)
        return blank_norm, blank_quant, True

    suppressed = np.where(inverted_arr < otsu_th * 0.7, 0, inverted_arr).astype(np.uint8)

    # 4. Bounding box ROI cropping
    ymin, ymax, xmin, xmax = extract_bounding_box(suppressed, threshold=int(otsu_th * 0.5))
    cropped = suppressed[ymin:ymax + 1, xmin:xmax + 1]

    # 5. Aspect-ratio preserving scaling into 20x20
    crop_h, crop_w = cropped.shape
    if crop_h > 0 and crop_w > 0:
        scale = float(target_box_size) / max(crop_h, crop_w)
        new_w = max(1, int(round(crop_w * scale)))
        new_h = max(1, int(round(crop_h * scale)))
        cropped_pil = Image.fromarray(cropped).resize((new_w, new_h), Image.Resampling.BICUBIC)
        resized_arr = np.array(cropped_pil, dtype=np.float32)
    else:
        resized_arr = np.zeros((target_box_size, target_box_size), dtype=np.float32)

    # 6. Center-of-Mass alignment onto 28x28 canvas
    canvas = np.zeros((canvas_size, canvas_size), dtype=np.float32)
    r_h, r_w = resized_arr.shape
    start_y = (canvas_size - r_h) // 2
    start_x = (canvas_size - r_w) // 2
    canvas[start_y:start_y + r_h, start_x:start_x + r_w] = resized_arr

    cy, cx = compute_center_of_mass(canvas)
    shift_y = int(round(canvas_size / 2.0 - cy))
    shift_x = int(round(canvas_size / 2.0 - cx))
    shifted_canvas = np.roll(canvas, shift_y, axis=0)
    shifted_canvas = np.roll(shifted_canvas, shift_x, axis=1)

    # 7. Range normalization to [0.0, 1.0) and fixed-point scale (256)
    max_val = np.max(shifted_canvas)
    if max_val > 0:
        norm_img = (shifted_canvas / 255.0).astype(np.float32)
    else:
        norm_img = shifted_canvas.astype(np.float32)

    quant_img = np.clip(np.round(norm_img * FIXED_SCALE), 0, 255).astype(np.int16)
    return norm_img, quant_img, False


def is_blank_or_noise_sample(img_path_or_arr, max_logit_float=None, logit_threshold=0.5) -> bool:
    """
    Evaluates whether a sample is a negative control (blank paper, scratch, clutter).
    Rejection criteria:
    1. Preprocessing foreground stroke detection flags empty / low mass.
    2. Model output confidence (max logit) falls below rejection threshold (e.g. 0.5).
    """
    if max_logit_float is not None and max_logit_float < logit_threshold:
        return True

    if img_path_or_arr is None:
        return False

    if isinstance(img_path_or_arr, str):
        pil_img = Image.open(img_path_or_arr)
    elif isinstance(img_path_or_arr, Image.Image):
        pil_img = img_path_or_arr
    elif isinstance(img_path_or_arr, np.ndarray):
        pil_img = Image.fromarray(img_path_or_arr)
    else:
        return True

    gray = np.array(rgb_to_grayscale(pil_img), dtype=np.uint8)
    if float(np.std(gray)) < 5.0:
        return True

    inv = invert_if_needed(gray)
    th = otsu_threshold(inv)
    fg_pixels = np.sum(inv > max(th, 30))
    # If foreground ink mass is less than 50 pixels in raw image, reject
    if fg_pixels < 50:
        return True
    return False


def compute_confusion_matrix(y_true: list, y_pred: list, num_classes=10) -> np.ndarray:
    """Computes a 10x10 confusion matrix where rows are ground truth, cols are predicted."""
    cm = np.zeros((num_classes, num_classes), dtype=np.int32)
    for t, p in zip(y_true, y_pred):
        if 0 <= t < num_classes and 0 <= p < num_classes:
            cm[t, p] += 1
    return cm


def compute_precision_recall(cm: np.ndarray):
    """Computes per-class precision and recall from a confusion matrix."""
    num_classes = cm.shape[0]
    precision = np.zeros(num_classes, dtype=np.float32)
    recall = np.zeros(num_classes, dtype=np.float32)

    for c in range(num_classes):
        tp = cm[c, c]
        pred_c = np.sum(cm[:, c])
        true_c = np.sum(cm[c, :])

        precision[c] = (tp / pred_c) if pred_c > 0 else 0.0
        recall[c] = (tp / true_c) if true_c > 0 else 0.0

    return precision, recall


# Synthetic boundary generators for corner-case verification
def get_all_zeros_vector() -> np.ndarray:
    return np.zeros(784, dtype=np.float32)


def get_all_max_vector() -> np.ndarray:
    return np.full(784, FIXED_MAX_FLOAT, dtype=np.float32)


def get_all_min_vector() -> np.ndarray:
    return np.full(784, FIXED_MIN_FLOAT, dtype=np.float32)


def get_alternating_vector() -> np.ndarray:
    arr = np.empty(784, dtype=np.float32)
    arr[0::2] = FIXED_MAX_FLOAT
    arr[1::2] = FIXED_MIN_FLOAT
    return arr


def get_single_hot_vector(hot_idx=392, val=1.0) -> np.ndarray:
    arr = np.zeros(784, dtype=np.float32)
    arr[hot_idx] = val
    return arr

