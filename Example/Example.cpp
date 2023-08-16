#include "EsdCppApp.h"  // Include the header file for the EsdApp class and related functionality.

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