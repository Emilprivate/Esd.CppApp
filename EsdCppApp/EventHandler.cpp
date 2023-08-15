#include "EventHandler.h"
#include "EsdCppApp.h"
#include <imgui_impl_sdl2.h>

namespace EsdCppApp {
    void EventHandler::HandleEvent(bool& isActive)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                isActive = false;
        }
    }
}