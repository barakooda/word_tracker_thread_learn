# run.sh
#!/bin/bash
set -e

# Get the absolute path to the project root
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
APP="$PROJECT_ROOT/bin/WordTracker"

if [[ ! -f "$APP" ]]; then
    echo "Application not found. Please build the project first."
    exit 1
fi

echo "Running WordTracker application..."
"$APP"
