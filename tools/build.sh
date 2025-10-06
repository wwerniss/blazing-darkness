#!/bin/bash

set -e
echo "🚀 Starting build process..."
mkdir -p build
cd build

echo "🛠️  Configuring project with CMake..."
cmake .. -DCMAKE_BUILD_TYPE=Release

echo "🔨 Building project..."
cmake --build . --config Release -- -j$(sysctl -n hw.ncpu)

echo "✅ Build completed successfully!"
echo "💡 You can run the game with: ./tools/run.sh"