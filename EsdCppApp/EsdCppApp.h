#pragma once
#include <string>
#include "ImGuiLayer.h"
#include "EventHandler.h"

namespace EsdCppApp
{
    // The EsdApp class serves as the core application layer for managing the application.
    class EsdApp {
    public:
        // Initializes application with the given title, width, and height.
        static void StartLayer(const std::string& title, int width, int height);

        // Cleans up resources allocated during application start-up.
        static void EndLayer();

        // Gets the ImGuiLayer instance associated with this application.
        static ImGuiLayer* GetImGuiLayer();

        // Gets the EventHandler instance associated with this application.
        static EventHandler* GetEventHandler();
    };
}
