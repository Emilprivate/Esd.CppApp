#include "EsdCppApp.h"
#include "Window.h"
#include "ImGuiLayer.h"

namespace EsdCppApp {

    static Window* appWindow = nullptr;     // The window instance for the application.
    static ImGuiLayer* imguiLayer = nullptr; // The ImGui layer instance for the application.
    static EventHandler* eventHandler = nullptr; // The event handler instance for the application.

    // Initializes the application layer with a new Window and ImGuiLayer.
    void EsdApp::StartLayer(const std::string& title, int width, int height)
    {
        appWindow = new Window(title, width, height);
        imguiLayer = new ImGuiLayer(appWindow->GetSDLWindow(), appWindow->GetGLContext());
    }

    // Cleans up the ImGuiLayer and Window instances created during StartLayer.
    void EsdApp::EndLayer()
    {
        delete imguiLayer;
        delete appWindow;
    }

    // Returns the ImGuiLayer instance associated with this application.
    ImGuiLayer* EsdApp::GetImGuiLayer()
    {
        return imguiLayer;
    }

    // Returns the EventHandler instance associated with this application.
    EventHandler* EsdApp::GetEventHandler()
    {
        return eventHandler;
    }
}