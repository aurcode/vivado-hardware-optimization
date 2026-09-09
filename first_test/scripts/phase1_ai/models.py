import torch
import torch.nn as nn
import torch.nn.functional as F

class HardwareMLP(nn.Module):
    """
    Hardware-Constrained Multi-Layer Perceptron for MNIST (28x28).
    Strictly adheres to hardware constraints:
    - Zero bias parameters (omit bias to reduce DSP/LUT usage).
    - Sign-bit ReLU activations (f(x) = x if x > 0 else 0).
    - Fully synthesizable layer topology: 784 -> 128 -> 64 -> 10.
    """
    def __init__(self, input_dim=784, hidden1_dim=128, hidden2_dim=64, num_classes=10):
        super(HardwareMLP, self).__init__()
        self.input_dim = input_dim
        self.hidden1_dim = hidden1_dim
        self.hidden2_dim = hidden2_dim
        self.num_classes = num_classes

        # Strict Hardware Pruning: bias=False across all layers
        self.fc1 = nn.Linear(input_dim, hidden1_dim, bias=False)
        self.fc2 = nn.Linear(hidden1_dim, hidden2_dim, bias=False)
        self.fc3 = nn.Linear(hidden2_dim, num_classes, bias=False)

    def forward(self, x):
        # Flatten (B, 1, 28, 28) -> (B, 784)
        if x.dim() > 2:
            x = x.view(x.size(0), -1)
        
        # Layer 1
        z1 = self.fc1(x)
        a1 = F.relu(z1)

        # Layer 2
        z2 = self.fc2(a1)
        a2 = F.relu(z2)

        # Layer 3 (logits)
        out = self.fc3(a2)
        return out

    def forward_with_intermediates(self, x):
        """
        Returns layer-by-layer intermediate tensors for bit-accurate verification.
        """
        if x.dim() > 2:
            x = x.view(x.size(0), -1)
        
        z1 = self.fc1(x)
        a1 = F.relu(z1)
        
        z2 = self.fc2(a1)
        a2 = F.relu(z2)
        
        out = self.fc3(a2)
        
        return {
            "input": x,
            "z1": z1,
            "a1": a1,
            "z2": z2,
            "a2": a2,
            "out": out
        }
