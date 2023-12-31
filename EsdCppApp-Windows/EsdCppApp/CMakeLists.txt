# Find the OpenGL library
find_package(OpenGL REQUIRED)

# Add imgui source files
set(IMGUI_SOURCES
        Libs/imgui/imgui.cpp
        Libs/imgui/imgui_draw.cpp
        Libs/imgui/imgui_widgets.cpp
        Libs/imgui/imgui_demo.cpp
        Libs/imgui/imgui_impl_sdl2.cpp
        Libs/imgui/imgui_impl_opengl2.cpp
        Libs/imgui/imgui_tables.cpp
        )

# Set the path to the SDL2 cmake configuration files
set(SDL2_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Libs/sdl/cmake")

# Find the SDL2 package
find_package(SDL2 REQUIRED)

# Create EsdCppApp library
add_library(EsdCppApp STATIC
        EsdCppApp.cpp
        EsdEventHandler.cpp
        EsdImGuiLayer.cpp
        EsdWindow.cpp
        ${IMGUI_SOURCES}
        )

# Add include directories for EsdCppApp library
target_include_directories(EsdCppApp PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/Libs/imgui
        ${SDL2_INCLUDE_DIRS}
        )

# Link EsdCppApp library with SDL2 and OpenGL
target_link_libraries(EsdCppApp
        PUBLIC
        ${SDL2_LIBRARIES}
        ${OPENGL_LIBRARIES}
        )
