#!/bin/bash

# Exit on error
set -e

# Clean and create build directory
echo "🧹 Cleaning build directory..."
rm -rf build
mkdir -p build
cd build

# CMake configuration
echo "⚙️ Configuring CMake..."
cmake ..

# Build project
echo "🔨 Building project..."
# Use sysctl for macOS instead of nproc
make -j$(sysctl -n hw.ncpu)

# Run tests based on the provided argument
echo "🏃 Running all tests..."
# ctest --output-on-failure # --verbose
./unit_tests

echo "✅ Testing completed!"