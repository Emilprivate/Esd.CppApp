#!/bin/bash

# Navigate to the EsdCppApp-Src directory, where CMakeLists.txt is located
cd EsdCppApp-Src

# Create a new directory for the build artifacts
mkdir -p build

# Navigate to the build directory
cd build

# Run CMake to configure the project
cmake ..

# Run Make to build the project
make

# Return to the original directory
cd ../..

# Print a success message
echo "Build completed"
