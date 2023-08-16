#pragma once
#include <SDL.h>

namespace EsdCppApp {

    // The EventHandler class is responsible for processing system events.
    class EventHandler {
    public:
        // Handles events from the SDL event queue, and updates the application state accordingly.
        void HandleEvent(bool& isActive);
    };
}
