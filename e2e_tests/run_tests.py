#!/usr/bin/env python3
"""Entry point alias for e2e_tests/test_runner.py."""
import os
import sys

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
REPO_ROOT = os.path.dirname(SCRIPT_DIR)
if REPO_ROOT not in sys.path:
    sys.path.insert(0, REPO_ROOT)

from e2e_tests.test_runner import main

if __name__ == "__main__":
    main()
