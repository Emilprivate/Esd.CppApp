#pragma once
#include <SDL.h>
#include <string>

namespace EsdCppApp
{
    // The Window class encapsulates the SDL_Window and associated SDL_GLContext for OpenGL rendering.
    class Window {
    public:
        // Constructor: Initializes the SDL video subsystem, creates a window, and an OpenGL context.
        Window(const std::string& title, int width, int height);

        // Destructor: Cleans up the created SDL_GLContext, SDL_Window, and quits SDL subsystem.
        ~Window();

        // Returns the SDL_Window instance associated with this Window object.
        SDL_Window* GetSDLWindow();

        // Returns the SDL_GLContext associated with this Window object.
        SDL_GLContext GetGLContext();

    private:
        SDL_Window* m_Window;     // The SDL window handle.
        SDL_GLContext m_GLContext; // The OpenGL context associated with the SDL window.
    };
}