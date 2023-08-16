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

# Add the executable target
add_executable(ExampleApp Example.cpp)

# Include directories for the example
target_include_directories(ExampleApp PRIVATE
        ${EsdCppApp_INCLUDE_DIR}
        ${ImGui_INCLUDE_DIR}
        ${OPENGL_INCLUDE_DIR}
        )

# Link against the libraries
target_link_libraries(ExampleApp PRIVATE
        "${EsdCppApp_LIB_DIR}/libEsdCppApp.a"
        SDL2::SDL2
        OpenGL::GL
        )

# Check the operating system
if(APPLE)
    message(STATUS "Running on macOS.")
    # macOS specific flags and settings here
    target_link_libraries(ExampleApp PRIVATE "-framework CoreVideo")

elseif(UNIX AND NOT APPLE)
    message(STATUS "Running on a Unix-like system.")
    # Linux/Unix specific flags and settings here

elseif(WIN32)
    message(STATUS "Running on Windows.")
    # Windows specific flags and settings here
    # Example: Copy DLLs to the output directory
    # add_custom_command(TARGET ExampleApp POST_BUILD
    #     COMMAND ${CMAKE_COMMAND} -E copy_if_different
    #     "${SDL2_DLL_DIR}/SDL2.dll"
    #     $<TARGET_FILE_DIR:ExampleApp>
    # )
endif()
