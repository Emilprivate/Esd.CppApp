# Esd.CppApp
Custom SDL+ImGui Cross-Platform Desktop Application Template/Library for easy start-up of future projects. This template also makes the SDL window invisible to the user, so that the user can focus on the ImGui user interface elements..

![](https://github.com/Emilprivate/Esd.CppApp/blob/main/Logo.png)

## Usage
```cpp
#include "../EsdCppApp.h"  // Include the header file for the EsdApp class and related functionality.

#define WIDTH 1280          // Define the width of the application window.
#define HEIGHT 720          // Define the height of the application window.
#define TITLE "Esd.CppApp"  // Define the title of the application window.

// Entry point for the application.
int main(int, char**)
{
    // Define a lambda function that contains the user interface elements for the application.
    // In this case, it simply displays ImGui's built-in demo window.
    auto myApp = []()
    {
        ImGui::ShowDemoWindow();  // Show the ImGui demo window to demonstrate ImGui's functionalities.
    };

    // Declare a boolean flag to indicate whether the application is running or not.
    bool running = true;

    // Initialize the application with a title, width, and height.
    EsdCppApp::EsdApp::StartLayer(TITLE, WIDTH, HEIGHT);

    // Run the application layer, which handles events, updates the application state, and renders the application.
    EsdCppApp::EsdApp::RunLayer(myApp, running);

    // Perform cleanup operations for the application layer, such as deleting allocated resources.
    EsdCppApp::EsdApp::EndLayer();

    // Return 0 to indicate successful termination of the application.
    return 0;
}
```

# How to Use the EsdCppApp Library
## Prerequisites
### Install Git:
Install Git from https://git-scm.com/

### Install CMake:
Install CMake from https://cmake.org/download/

### Install SDL2:
#### macOS:
```bash
brew install sdl2
```
#### Windows:
1. Download SDL2 from https://libsdl.org/download-2.0.php, place SDL2 in your C:\ folder or change the directory in the build.bat/generate files for a custom location.

#### Linux:
```bash
sudo apt-get install libsdl2-dev
```

### Install OpenGL:
This is usually pre-installed on macOS and Linux.
On Windows, OpenGL comes with graphics drivers.

## Step 1: Clone the Repository
Clone the GitHub repository containing the EsdCppApp library:
```bash
git clone https://github.com/Emilprivate/Esd.CppApp.git
```

## Step 2: Include the EsdCppApp Library in Your Project
Copy the EsdCppApp folder (which contains the includes and lib folders) into your project directory.

### In your CMakeLists.txt file:
Set the directories containing library headers:
```
set(EsdCppApp_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/EsdCppApp/includes")
```

Set the directories containing library binaries:
```
set(EsdCppApp_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/EsdCppApp/lib")
```

Include directories for your project:
```
target_include_directories(YourProjectName PRIVATE
        ${EsdCppApp_INCLUDE_DIR}
        ${OPENGL_INCLUDE_DIR}
        )
```

Link against the libraries:
```
target_link_libraries(YourProjectName PRIVATE
        "${EsdCppApp_LIB_DIR}/libEsdCppApp.a"
        SDL2::SDL2
        OpenGL::GL
        )
```

## Step 3: Build Your Project
### On macOS and Linux:
Navigate to your project's directory and run:
```bash
mkdir build
cd build
cmake ..
make
```
### On Windows:
Use CMake GUI or command line to generate build files for your preferred compiler, then build your project with that compiler.

## Step 4: Run the Example Project
After building, you can run your project executable, which should be located in the build directory.

## Step 5: Include the Library in Your Code
In your .cpp files where you need to use the EsdCppApp library, include the header file:
````
#include "EsdCppApp.h"
````
And then you can use the classes and functions as demonstrated in the Example.cpp file in your repository.

## To Build the Library:

### On Unix (Linux, macOS, etc.):

```sh
./build_lib.sh
```

### On Windows:
````
build_lib.bat
````

## To Generate IDE Project Files:
### For Visual Studio (Windows):
```
generate_vs_project.bat
```
### For Unix Makefiles (Linux, macOS, etc.):
```
./generate_unix_project.sh
```
