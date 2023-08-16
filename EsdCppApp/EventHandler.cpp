#include "EventHandler.h"
#include <imgui_impl_sdl2.h>

namespace EsdCppApp
{
    // Loops through SDL events and handles each event accordingly.
    // Updates the isActive flag when a quit event is detected.
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