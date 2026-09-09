#!/usr/bin/env python3
"""
Intelligent Chip Hardware Accelerator E2E Test Suite Runner.
Executes opaque-box verification across Tiers 1 through 4 covering Features 1-22.

CLI Flags:
  --tier {1,2,3,4}   Run a specific test tier
  --all              Run all test tiers (1 through 4)
  --feature N        Run tests specifically targeting Feature N (1..22)
  --list             List all discovered test cases without executing
  -v, --verbose      Detailed per-test output
"""

import os
import sys
import time
import argparse
import unittest

# Ensure repo root is on sys.path
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
REPO_ROOT = os.path.dirname(SCRIPT_DIR)
if REPO_ROOT not in sys.path:
    sys.path.insert(0, REPO_ROOT)

from e2e_tests.tier1_feature_tests import TestTier1Features
from e2e_tests.tier2_boundary_tests import TestTier2Boundaries
from e2e_tests.tier3_interaction_tests import TestTier3Interactions
from e2e_tests.tier4_workload_tests import TestTier4Workloads


TIER_CLASSES = {
    1: (TestTier1Features, "Tier 1: Feature Coverage (Features 1-22)"),
    2: (TestTier2Boundaries, "Tier 2: Boundary & Corner Cases"),
    3: (TestTier3Interactions, "Tier 3: Cross-Feature Interactions"),
    4: (TestTier4Workloads, "Tier 4: Real-World Workload Scenarios")
}


class CustomTestResult(unittest.TestResult):
    def __init__(self, verbose=False):
        super().__init__()
        self.verbose = verbose
        self.test_details = []

    def startTest(self, test):
        super().startTest(test)
        test._start_time = time.time()
        if self.verbose:
            sys.stdout.write(f"  [RUN] {test._testMethodName:<60} ... ")
            sys.stdout.flush()

    def addSuccess(self, test):
        super().addSuccess(test)
        elapsed = time.time() - getattr(test, "_start_time", time.time())
        self.test_details.append((test._testMethodName, "PASS", elapsed, None))
        if self.verbose:
            sys.stdout.write(f"[PASS] ({elapsed:.3f}s)\n")

    def addFailure(self, test, err):
        super().addFailure(test, err)
        elapsed = time.time() - getattr(test, "_start_time", time.time())
        self.test_details.append((test._testMethodName, "FAIL", elapsed, err))
        if self.verbose:
            sys.stdout.write(f"[FAIL] ({elapsed:.3f}s)\n")

    def addError(self, test, err):
        super().addError(test, err)
        elapsed = time.time() - getattr(test, "_start_time", time.time())
        self.test_details.append((test._testMethodName, "ERROR", elapsed, err))
        if self.verbose:
            sys.stdout.write(f"[ERROR] ({elapsed:.3f}s)\n")


def build_suite_for_tier(tier: int, feature_filter: int = None) -> unittest.TestSuite:
    test_cls, _ = TIER_CLASSES[tier]
    loader = unittest.TestLoader()
    suite = loader.loadTestsFromTestCase(test_cls)

    if feature_filter is not None:
        prefix1 = f"test_f{feature_filter}_"
        prefix2 = f"test_f{feature_filter:02d}_"
        prefix3 = f"test_f{feature_filter}b"
        filtered_tests = [
            t for t in suite
            if t._testMethodName.startswith(prefix1) or
               t._testMethodName.startswith(prefix2) or
               t._testMethodName.startswith(prefix3)
        ]
        new_suite = unittest.TestSuite()
        new_suite.addTests(filtered_tests)
        return new_suite

    return suite


def run_tier(tier: int, feature_filter: int = None, verbose: bool = False):
    _, tier_name = TIER_CLASSES[tier]
    suite = build_suite_for_tier(tier, feature_filter)
    count = suite.countTestCases()

    if count == 0:
        return {"tier": tier, "name": tier_name, "total": 0, "passed": 0, "failed": 0, "duration": 0.0, "errors": []}

    print(f"\n>> Running {tier_name} ({count} tests)...")
    start_time = time.time()

    result = CustomTestResult(verbose=verbose)
    suite.run(result)
    elapsed = time.time() - start_time

    passed = count - len(result.failures) - len(result.errors)
    failed = len(result.failures) + len(result.errors)

    error_msgs = []
    for test, err in result.failures:
        error_msgs.append((test._testMethodName, "FAIL", err))
    for test, err in result.errors:
        error_msgs.append((test._testMethodName, "ERROR", err))

    return {
        "tier": tier,
        "name": tier_name,
        "total": count,
        "passed": passed,
        "failed": failed,
        "duration": elapsed,
        "errors": error_msgs
    }


def list_tests():
    print("=" * 78)
    print("  Discovered Test Inventory (Tiers 1-4, Features 1-22)")
    print("=" * 78)
    total = 0
    for tier in [1, 2, 3, 4]:
        _, name = TIER_CLASSES[tier]
        suite = build_suite_for_tier(tier)
        print(f"\n[+] {name} ({suite.countTestCases()} test cases):")
        for t in suite:
            doc = (t._testMethodDoc or "").strip()
            print(f"    - {t._testMethodName:<60} {doc[:40]}")
            total += 1
    print(f"\nTotal test cases registered: {total}")
    print("=" * 78)


def main():
    parser = argparse.ArgumentParser(
        description="E2E Test Runner for Intelligent Chip Hardware Accelerator"
    )
    group = parser.add_mutually_exclusive_group()
    group.add_argument(
        "--tier", type=int, choices=[1, 2, 3, 4],
        help="Run only the specified test tier (1, 2, 3, or 4)"
    )
    group.add_argument(
        "--all", action="store_true", default=True,
        help="Run all test tiers (default)"
    )
    group.add_argument(
        "--list", action="store_true",
        help="List all registered test cases without executing"
    )

    parser.add_argument(
        "--feature", type=int, choices=range(1, 23),
        help="Filter tests for specific Feature N (1..22)"
    )
    parser.add_argument(
        "-v", "--verbose", action="store_true",
        help="Display verbose per-test execution traces"
    )

    args = parser.parse_args()

    if args.list:
        list_tests()
        sys.exit(0)

    tiers_to_run = [args.tier] if args.tier else [1, 2, 3, 4]

    print("=" * 82)
    print("  INTELLIGENT CHIP HARDWARE ACCELERATOR - E2E TEST SUITE")
    print("  Scope: 784-64-10 MLP Core, 16-SIMD TDM Reuse, 7-Step Preprocessing, DSE")
    print("=" * 82)

    tier_results = []
    overall_start = time.time()

    for t in tiers_to_run:
        res = run_tier(t, feature_filter=args.feature, verbose=args.verbose)
        tier_results.append(res)

    total_time = time.time() - overall_start

    # Summary table
    print("\n" + "=" * 82)
    print(f"{'Tier / Verification Scope':<42} | {'Total':<6} | {'Pass':<6} | {'Fail':<6} | {'Time (s)':<8}")
    print("-" * 82)

    total_tests = sum(r["total"] for r in tier_results)
    total_passed = sum(r["passed"] for r in tier_results)
    total_failed = sum(r["failed"] for r in tier_results)

    for r in tier_results:
        print(f"{r['name']:<42} | {r['total']:<6} | {r['passed']:<6} | {r['failed']:<6} | {r['duration']:6.2f}s")

    print("-" * 82)
    pass_pct = (100.0 * total_passed / total_tests) if total_tests > 0 else 0.0
    print(f"{'OVERALL TOTAL':<42} | {total_tests:<6} | {total_passed:<6} | {total_failed:<6} | {total_time:6.2f}s")
    print(f"Pass Rate: {pass_pct:.2f}%")

    if total_failed > 0:
        print("\n[!] DETECTED TEST FAILURES / ERRORS:")
        for r in tier_results:
            for test_name, status, err in r["errors"]:
                print(f"    - [{status}] {test_name} in {r['name']}")
                # print summary of error
                lines = err.splitlines()
                summary_line = lines[-1] if lines else "Unknown error"
                print(f"        Reason: {summary_line}")
        print("=" * 82)
        print("RESULT: FAILED")
        sys.exit(1)
    else:
        print("=" * 82)
        print("RESULT: ALL TESTS PASSED (100% SUCCESS)")
        sys.exit(0)


if __name__ == "__main__":
    main()
