#!/bin/bash
set -e

# Get the absolute path to the project root
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
TEST_EXE="$PROJECT_ROOT/bin/tests"

if [[ ! -f "$TEST_EXE" ]]; then
    echo "Tests executable not found. Please build the project first."
    exit 1
fi

echo "Running tests..."
"$TEST_EXE"
