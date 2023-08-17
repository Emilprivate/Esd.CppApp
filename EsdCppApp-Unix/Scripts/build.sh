#!/bin/sh

# Get the location of this script
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

# Navigate to the project root (assumes the script is in a directory under the project root)
cd "$SCRIPT_DIR/.."

# Create a new 'build' directory, or navigate to it if it already exists
mkdir -p build
cd build

# Run CMake to generate the Makefiles
cmake ..

# Print message
echo "To build the project, navigate to the 'build' directory and run 'make'."
