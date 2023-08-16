#pragma once
#include <string>
#include "EsdImGuiLayer.h"
#include "EsdEventHandler.h"

namespace EsdCppApp
{
    // The EsdApp class serves as the core application layer for managing the application.
    class EsdApp {
    public:
        // Initializes application with the given title, width, and height.
        static void StartLayer(const char* title, const float width, const float height);

        // Runs the application layer, which handles events, updates the application state, and renders the application.
        static void RunLayer(void(*userAppUI)(), bool& isActive);

        // Cleans up resources allocated during application start-up.
        static void EndLayer();

        // Gets the EsdImGuiLayer instance associated with this application.
        static EsdImGuiLayer* GetImGuiLayer();

        // Gets the EsdEventHandler instance associated with this application.
        static EsdEventHandler* GetEventHandler();
    };
}
