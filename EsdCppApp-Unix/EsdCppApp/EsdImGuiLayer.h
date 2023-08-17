#pragma once
#include <string>
#include <SDL.h>
#include <SDL_opengl.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl2.h>

namespace EsdCppApp
{
    // The EsdImGuiLayer class encapsulates the functionality to handle ImGui rendering.
    class EsdImGuiLayer {
    public:
        // Constructor: Initializes ImGui context and sets up ImGui for SDL2 and OpenGL.
        EsdImGuiLayer(const char* title, const float w, const float h, SDL_Window* window, SDL_GLContext glContext);

        // Destructor: Cleans up ImGui context and shutdown ImGui implementations for SDL2 and OpenGL.
        ~EsdImGuiLayer();

        // Handles the start of a new ImGui frame, sets up the ImGui context for the frame, and ends the frame after user UI code has run.
        void RunFrame(void(*userAppUI)(), bool& isActive);

        // Handles window resize events and updates ImGui's IO structure with the new window size.
        void ResizeEvent();

    private:
        SDL_Window* m_Window;     // The SDL window that ImGui will render to.
        SDL_GLContext m_GLContext; // The OpenGL context associated with the SDL window.
        const float width;
        const float height;
        const char* title;

        // Custom ImGui style.
        void DefaultEsdStyle();
    };
}