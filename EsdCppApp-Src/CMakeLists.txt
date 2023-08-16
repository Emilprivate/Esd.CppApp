cmake_minimum_required(VERSION 3.16)
project(EsdCppApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SDL2
find_package(SDL2 REQUIRED)

# Set ImGui directory
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libs/imgui)

# Automatically grab all .cpp files from the ImGui directory
file(GLOB IMGUI_SOURCES ${IMGUI_DIR}/*.cpp)

# Add the library target
file(GLOB_RECURSE LIB_SOURCES *.cpp *.h)
add_library(EsdCppApp STATIC ${LIB_SOURCES} ${IMGUI_SOURCES})

# Include directories for the library
target_include_directories(EsdCppApp PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${IMGUI_DIR}
        )

# Link SDL2 to your library
target_link_libraries(EsdCppApp PUBLIC SDL2::SDL2)