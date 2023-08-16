cmake_minimum_required(VERSION 3.16)
project(ExampleApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SDL2 and OpenGL
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

# Set the directories containing library headers
set(EsdCppApp_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/esdcppapp/includes")
set(ImGui_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui")

# Set the directories containing library binaries
set(EsdCppApp_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/esdcppapp/lib")

# Add ImGui sources directly to the application
file(GLOB IMGUI_SOURCES "${ImGui_INCLUDE_DIR}/*.cpp")

# Add the executable target
add_executable(ExampleApp Example.cpp ${IMGUI_SOURCES})

# Include directories for the example
target_include_directories(ExampleApp PRIVATE
        ${EsdCppApp_INCLUDE_DIR}
        ${ImGui_INCLUDE_DIR}
        ${OPENGL_INCLUDE_DIR}
        )

# Check the operating system
if(WIN32)
    message(STATUS "Running on Windows.")
    link_directories(${EsdCppApp_LIB_DIR})
    target_link_libraries(ExampleApp PRIVATE EsdCppApp SDL2::SDL2 OpenGL::GL)

    # Windows specific flags and settings here
    # Example: Copy DLLs to the output directory

elseif(APPLE)
    message(STATUS "Running on macOS.")
    target_link_libraries(ExampleApp PRIVATE
            "${EsdCppApp_LIB_DIR}/libEsdCppApp.a"
            SDL2::SDL2
            OpenGL::GL
            "-framework CoreVideo"
            )
    # macOS specific flags and settings here

elseif(UNIX AND NOT APPLE)
    message(STATUS "Running on a Unix-like system.")
    target_link_libraries(ExampleApp PRIVATE
            "${EsdCppApp_LIB_DIR}/libEsdCppApp.a"
            SDL2::SDL2
            OpenGL::GL
            )
    # Linux/Unix specific flags and settings here

else()
    message(SEND_ERROR "You are on an unsupported platform!")
endif()
