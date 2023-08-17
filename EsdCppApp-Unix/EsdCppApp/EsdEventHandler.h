#pragma once
#include <SDL.h>
#include <imgui_impl_sdl2.h>

namespace EsdCppApp {

    // The EsdEventHandler class is responsible for processing system events.
    class EsdEventHandler {
    public:
        // Handles events from the SDL event queue, and updates the application state accordingly.
        void HandleEvent(bool& isActive);
    };
}
