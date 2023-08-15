#include "Window.h"
#include <SDL_opengl.h>
#include <iostream>

namespace EsdCppApp {

    Window::Window(const std::string& title, int width, int height) {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            std::cerr << "Error: " << SDL_GetError() << "\n";
            exit(-1);
        }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

        m_Window = SDL_CreateWindow(title.c_str(),
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    width, height,
                                    SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

        if (m_Window == NULL) {
            std::cerr << "Error: " << SDL_GetError() << "\n";
            SDL_Quit();
            exit(-1);
        }

        m_GLContext = SDL_GL_CreateContext(m_Window);
        if (m_GLContext == NULL) {
            std::cerr << "Error: " << SDL_GetError() << "\n";
            SDL_DestroyWindow(m_Window);
            SDL_Quit();
            exit(-1);
        }
    }

    Window::~Window() {
        SDL_GL_DeleteContext(m_GLContext);
        SDL_DestroyWindow(m_Window);
        SDL_Quit();
    }

    SDL_Window* Window::GetSDLWindow() { return m_Window; }
    SDL_GLContext Window::GetGLContext() { return m_GLContext; }
}
