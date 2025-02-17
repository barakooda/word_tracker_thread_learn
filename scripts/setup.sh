#!/bin/bash

set -e  # Exit if any command fails

# Get the absolute path to the project root (important for running from anywhere)
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

# Function to clean previous builds
clean_build() {
    if [[ -d "$PROJECT_ROOT/build" || -d "$PROJECT_ROOT/bin" ]]; then
        echo "🧹 Cleaning previous build..."
        rm -rf "$PROJECT_ROOT/build" "$PROJECT_ROOT/bin"
        echo "✅ Clean completed."
    else
        echo "🟢 No previous build found. Skipping clean."
    fi
}

# Function to install dependencies
install_dependencies() {
    echo "🔹 Checking and installing dependencies..."
    sudo apt update
    sudo apt install -y g++ cmake make
}

# Function to build the project
build_project() {
    install_dependencies
    echo "🔹 Setting up build directory..."
    mkdir -p "$PROJECT_ROOT/build" && cd "$PROJECT_ROOT/build"

    echo "🔹 Running CMake configuration..."
    cmake -DCMAKE_BUILD_TYPE=Release "$PROJECT_ROOT"

    echo "🔹 Building the project..."
    cmake --build . --config Release -j$(nproc)

    echo "🔹 Running tests..."
    ctest --output-on-failure || echo "⚠️ Some tests failed!"

    echo "✅ Build completed successfully!"
}

# Interactive menu
while true; do
    echo ""
    echo "🔧 Setup Script - Choose an option:"
    echo "1) Build Project"
    echo "2) Clean Project"
    echo "3) Exit"
    read -p "Enter your choice: " choice

    case $choice in
        1) build_project ;;
        2) clean_build ;;
        3) echo "🚀 Exiting setup script."; exit 0 ;;
        *) echo "❌ Invalid choice. Please select 1, 2, or 3." ;;
    esac
done
