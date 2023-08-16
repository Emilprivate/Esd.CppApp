#include "EsdImGuiLayer.h"
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl2.h>
#include <SDL_opengl.h>
#include <iostream>

namespace EsdCppApp
{
    // Implementation of the constructor.
    EsdImGuiLayer::EsdImGuiLayer(SDL_Window* window, SDL_GLContext glContext)
            : m_Window(window), m_GLContext(glContext){

        IMGUI_CHECKVERSION();

        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ImGui::StyleColorsDark();

        ImGui_ImplSDL2_InitForOpenGL(m_Window, m_GLContext);
        ImGui_ImplOpenGL2_Init();

        std::cout << "EsdImGuiLayer initialized" << std::endl;
    }

    // Implementation of the destructor.
    EsdImGuiLayer::~EsdImGuiLayer()
    {
        ImGui_ImplOpenGL2_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
    }

    // Manages the entire lifecycle of an ImGui frame.
    void EsdImGuiLayer::RunFrame(void(*userAppUI)(), bool& isActive)
    {
        ImGuiIO& io = ImGui::GetIO();
        ResizeEvent();
        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplSDL2_NewFrame(m_Window);
        ImGui::NewFrame();

        // Create a window that fills the entire viewport and pass all events to the underlying window.
        ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x, io.DisplaySize.y), ImGuiCond_Always);
        ImGui::Begin("Background-Layer", &isActive, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBringToFrontOnFocus);
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
        ImGui::End();

        // Call the user's UI code.
        userAppUI();

        ImGui::Render();

        SDL_GL_MakeCurrent(m_Window, m_GLContext);

        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

        SDL_GL_SwapWindow(m_Window);
    }

    // Handles the updating of window size in ImGui when the SDL window is resized.
    void EsdImGuiLayer::ResizeEvent() {
        ImGuiIO& io = ImGui::GetIO();
        int width, height;
        SDL_GetWindowSize(m_Window, &width, &height);
        io.DisplaySize.x = static_cast<float>(width);
        io.DisplaySize.y = static_cast<float>(height);
    }
}
