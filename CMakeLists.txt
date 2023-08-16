cmake_minimum_required(VERSION 3.16)

# This is the super-project
project(EsdCppAppProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the library and the example as sub-projects
add_subdirectory(EsdCppApp-Src)
add_subdirectory(Example)
