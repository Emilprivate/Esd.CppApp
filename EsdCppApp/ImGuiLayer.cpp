#include "ImGuiLayer.h"
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl2.h>
#include <SDL_opengl.h>
#include <iostream>

namespace EsdCppApp
{
    ImGuiLayer::ImGuiLayer(SDL_Window* window, SDL_GLContext glContext)
            : m_Window(window), m_GLContext(glContext){

        IMGUI_CHECKVERSION();

        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        ImGui::StyleColorsDark();

        ImGui_ImplSDL2_InitForOpenGL(m_Window, m_GLContext);
        ImGui_ImplOpenGL2_Init();

        std::cout << "ImGuiLayer initialized" << std::endl;
    }

    ImGuiLayer::~ImGuiLayer()
    {
        ImGui_ImplOpenGL2_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::RunFrame(void(*userAppUI)(), bool& isActive)
    {
        ImGuiIO& io = ImGui::GetIO();
        ResizeEvent();
        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplSDL2_NewFrame(m_Window);
        ImGui::NewFrame();

        ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2(io.DisplaySize.x, io.DisplaySize.y), ImGuiCond_Always);
        ImGui::Begin("Background-Layer", &isActive, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBringToFrontOnFocus);
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
        ImGui::End();

        userAppUI();

        ImGui::Render();

        SDL_GL_MakeCurrent(m_Window, m_GLContext);

        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

        SDL_GL_SwapWindow(m_Window);
    }

    void ImGuiLayer::ResizeEvent() {
        ImGuiIO& io = ImGui::GetIO();
        int width, height;
        SDL_GetWindowSize(m_Window, &width, &height);
        io.DisplaySize.x = static_cast<float>(width);
        io.DisplaySize.y = static_cast<float>(height);
    }
}
