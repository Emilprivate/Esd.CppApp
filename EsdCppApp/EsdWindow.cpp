#include "EsdWindow.h"
#include <SDL_opengl.h>
#include <iostream>

namespace EsdCppApp
{
    // Implementation of the constructor.
    EsdWindow::EsdWindow(const std::string& title, int width, int height) {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            std::cerr << "Error: " << SDL_GetError() << "\n";
            exit(-1);
        }

        // Use OpenGL 2.1
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

        m_Window = SDL_CreateWindow(title.c_str(),
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    width, height,
                                    SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

        // Check that the window was successfully created
        if (m_Window == NULL)
        {
            std::cerr << "Error: " << SDL_GetError() << "\n";
            SDL_Quit();
            exit(-1);
        }

        // Create an OpenGL context associated with the window.
        m_GLContext = SDL_GL_CreateContext(m_Window);

        // Check that the OpenGL context was successfully created
        if (m_GLContext == NULL)
        {
            std::cerr << "Error: " << SDL_GetError() << "\n";
            SDL_DestroyWindow(m_Window);
            SDL_Quit();
            exit(-1);
        }
    }

    // Implementation of the destructor.
    EsdWindow::~EsdWindow() {
        SDL_GL_DeleteContext(m_GLContext);
        SDL_DestroyWindow(m_Window);
        SDL_Quit();
    }

    // Returns the SDL_Window instance associated with this EsdWindow object.
    SDL_Window* EsdWindow::GetSDLWindow() { return m_Window; }

    // Returns the SDL_GLContext associated with this EsdWindow object.
    SDL_GLContext EsdWindow::GetGLContext() { return m_GLContext; }
}
