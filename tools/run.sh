#!/bin/bash

set -e

GAME_EXECUTABLE="./build/BlazingDarkness"

if [ ! -f "$GAME_EXECUTABLE" ]; then
    echo "❌ Error: Game executable not found at $GAME_EXECUTABLE"
    echo "💡 Make sure to build the game first using the build script."
    exit 1
fi

chmod +x "$GAME_EXECUTABLE"

echo "🎮 Starting Blazing Darkness..."
"$GAME_EXECUTABLE"
if [ $? -eq 0 ]; then
    echo "👋 Thanks for playing Blazing Darkness!"
else
    echo "⚠️  The game exited with an error."
    exit 1
fi