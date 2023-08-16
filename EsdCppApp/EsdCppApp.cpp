#include "EsdCppApp.h"
#include "EsdWindow.h"
#include "EsdImGuiLayer.h"

namespace EsdCppApp {

    static EsdWindow* appWindow = nullptr;     // The window instance for the application.
    static EsdImGuiLayer* imguiLayer = nullptr; // The ImGui layer instance for the application.
    static EsdEventHandler* eventHandler = nullptr; // The event handler instance for the application.

    // Initializes the application layer with a new EsdWindow and EsdImGuiLayer.
    void EsdApp::StartLayer(const char* title, const float width, const float height)
    {
        appWindow = new EsdWindow();
        imguiLayer = new EsdImGuiLayer(title, width, height, appWindow->GetSDLWindow(), appWindow->GetGLContext());
    }

    // Runs the application layer, which handles events, updates the application state, and renders the application.
    void EsdApp::RunLayer(void (*userAppUI)(), bool &isActive)
    {
        // Main loop: continue to run the application as long as 'running' is true.
        while (isActive) {
            // Poll and handle events from the event queue.
            // Update the 'running' flag based on the events (e.g., exit when a quit event is detected).
            EsdApp::GetEventHandler()->HandleEvent(isActive);

            // Run an ImGui frame by calling the lambda function 'myApp' which is passed as an argument,
            // and also pass the 'running' flag to allow the GUI layer to potentially modify the application's running state.
            EsdApp::GetImGuiLayer()->RunFrame(userAppUI, isActive);
        }
    }

    // Cleans up the EsdImGuiLayer and EsdWindow instances created during StartLayer.
    void EsdApp::EndLayer()
    {
        delete imguiLayer;
        delete appWindow;
    }

    // Returns the EsdImGuiLayer instance associated with this application.
    EsdImGuiLayer* EsdApp::GetImGuiLayer()
    {
        return imguiLayer;
    }

    // Returns the EsdEventHandler instance associated with this application.
    EsdEventHandler* EsdApp::GetEventHandler()
    {
        return eventHandler;
    }
}