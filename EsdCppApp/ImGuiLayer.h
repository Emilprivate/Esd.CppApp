#pragma once
#include <SDL.h>
#include <imgui.h>

namespace EsdCppApp
{
    // The ImGuiLayer class encapsulates the functionality to handle ImGui rendering.
    class ImGuiLayer {
    public:
        // Constructor: Initializes ImGui context and sets up ImGui for SDL2 and OpenGL.
        ImGuiLayer(SDL_Window* window, SDL_GLContext glContext);

        // Destructor: Cleans up ImGui context and shutdown ImGui implementations for SDL2 and OpenGL.
        ~ImGuiLayer();

        // Handles the start of a new ImGui frame, sets up the ImGui context for the frame, and ends the frame after user UI code has run.
        void RunFrame(void(*userAppUI)(), bool& isActive);

        // Handles window resize events and updates ImGui's IO structure with the new window size.
        void ResizeEvent();

    private:
        SDL_Window* m_Window;     // The SDL window that ImGui will render to.
        SDL_GLContext m_GLContext; // The OpenGL context associated with the SDL window.
    };
}