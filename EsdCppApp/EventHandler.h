#pragma once
#include <SDL.h>

namespace EsdCppApp {

    class EventHandler {
    public:
        void HandleEvent(bool& isActive);
    };
}