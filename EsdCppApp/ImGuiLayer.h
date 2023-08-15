#pragma once
#include <SDL.h>
#include <imgui.h>

namespace EsdCppApp {

    class ImGuiLayer {
    public:
        ImGuiLayer(SDL_Window* window, SDL_GLContext glContext);
        ~ImGuiLayer();

        void RunFrame(void(*userAppUI)(), bool& isActive);
        void ResizeEvent();

    private:
        SDL_Window* m_Window;
        SDL_GLContext m_GLContext;
    };
}

