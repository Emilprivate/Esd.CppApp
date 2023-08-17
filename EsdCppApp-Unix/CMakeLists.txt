cmake_minimum_required(VERSION 3.10)

# Set C++11 as the standard for the entire project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project name
project(Esd.CppApp-Unix)

# Add the EsdCppApp directory to the project
add_subdirectory(EsdCppApp)

# Example executable that demonstrates how to use your EsdCppApp library
add_subdirectory(Example)