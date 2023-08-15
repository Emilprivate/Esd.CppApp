#include "EsdCppApp.h"
#include "Window.h"
#include "ImGuiLayer.h"

namespace EsdCppApp {

    static Window* appWindow = nullptr;
    static ImGuiLayer* imguiLayer = nullptr;
    static EventHandler* eventHandler = nullptr;

    void EsdApp::StartLayer(const std::string& title, int width, int height) {
        appWindow = new Window(title, width, height);
        imguiLayer = new ImGuiLayer(appWindow->GetSDLWindow(), appWindow->GetGLContext());
    }

    void EsdApp::EndLayer() {
        delete imguiLayer;
        delete appWindow;
    }

    ImGuiLayer* EsdApp::GetImGuiLayer() {
        return imguiLayer;
    }

    EventHandler* EsdApp::GetEventHandler() {
        return eventHandler;
    }
}
