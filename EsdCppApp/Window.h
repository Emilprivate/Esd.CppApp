#pragma once
#include <SDL.h>
#include <string>

namespace EsdCppApp {

    class Window {
    public:
        Window(const std::string& title, int width, int height);
        ~Window();

        SDL_Window* GetSDLWindow();
        SDL_GLContext GetGLContext();

    private:
        SDL_Window* m_Window;
        SDL_GLContext m_GLContext;
    };
}
