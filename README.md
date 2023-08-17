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

## Unix/Apple Dependency Installation

On Unix-like systems, you can usually install these dependencies using your package manager. For example, on Debian-based systems (including Ubuntu), run:

```bash
sudo apt-get update
sudo apt-get install libsdl2-dev libgl1-mesa-dev
```
On macOS, you can use Homebrew:
```
brew update
brew install sdl2
```

## Windows Dependency Installation
On Windows, you'll need to manually configure the SDL2 and OpenGL dependencies through Visual Studio. The required files for these dependencies are already included in the Libs folder of the repository.

SDL2 Setup: Follow [this guide](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/index.php) to set up SDL2 with Visual Studio.

OpenGL Setup: OpenGL libraries are usually shipped with your graphics drivers, but you will need to link against these libraries in your Visual Studio project.

## Building the Library on Unix/Apple
To build the project on Unix-like systems, follow these steps:

Clone this repository:
```bash
git clone https://github.com/EmilPrivate/Esd.CppApp.git
```
Navigate to the cloned repository directory:
```bash
cd Esd.CppApp/EsdCppApp-Unix
```
Run the build.sh script:
```bash
chmod +x Scripts/build.sh
./Scripts/build.sh
```
To build the project, navigate to the 'build' directory and run:
```bash
make
```
To run the project, run:
```bash
./Example/EsdCppAppExample
```

## Building the Library on Windows
To build the project on Windows, follow these steps:
```
git clone https://github.com/EmilPrivate/Esd.CppApp.git
```
Navigate to the cloned repository directory.
```
cd Esd.CppApp/EsdCppApp-Windows
```
Run the build.bat script:
```
Scripts/build.bat
```
1) Open the generated Visual Studio solution file in the build directory.

2) Build the EsdCppApp project. 

*Note that there is no Example project for the Windows version due to complications that I have not yet resolved. The generated visual studio solution file is for the library itself (.lib).*