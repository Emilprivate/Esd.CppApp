#include "../EsdCppApp.h"  // Include the header file for the EsdApp class and related functionality.

#define WIDTH 1280          // Define the width of the application window.
#define HEIGHT 720          // Define the height of the application window.
#define TITLE "Esd.CppApp"  // Define the title of the application window.

// Entry point for the application.
int main(int, char**)
{
    // Initialize the application with a title, width, and height.
    EsdCppApp::EsdApp::StartLayer(TITLE, WIDTH, HEIGHT);

    // Declare a boolean flag to indicate whether the application is running or not.
    bool running = true;

    // Define a lambda function that contains the user interface elements for the application.
    // In this case, it simply displays ImGui's built-in demo window.
    auto myApp = []()
    {
        ImGui::ShowDemoWindow();  // Show the ImGui demo window to demonstrate ImGui's functionalities.
    };

    // Main loop: continue to run the application as long as 'running' is true.
    while (running) {
        // Poll and handle events from the event queue.
        // Update the 'running' flag based on the events (e.g., exit when a quit event is detected).
        EsdCppApp::EsdApp::GetEventHandler()->HandleEvent(running);

        // Run an ImGui frame by calling the lambda function 'myApp' which is passed as an argument,
        // and also pass the 'running' flag to allow the GUI layer to potentially modify the application's running state.
        EsdCppApp::EsdApp::GetImGuiLayer()->RunFrame(myApp, running);
    }

    // Perform cleanup operations for the application layer, such as deleting allocated resources.
    EsdCppApp::EsdApp::EndLayer();

    // Return 0 to indicate successful termination of the application.
    return 0;
}