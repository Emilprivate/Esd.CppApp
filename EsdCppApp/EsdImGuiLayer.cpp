#include "EsdImGuiLayer.h"
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl2.h>
#include <SDL_opengl.h>

namespace EsdCppApp
{
    // Implementation of the constructor.
    EsdImGuiLayer::EsdImGuiLayer(const char* title, const float w, const float h, SDL_Window* window, SDL_GLContext glContext)
            : title(title), width(w), height(h), m_Window(window), m_GLContext(glContext){

        IMGUI_CHECKVERSION();

        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

        EsdImGuiLayer::DefaultEsdStyle();

        ImGui_ImplSDL2_InitForOpenGL(m_Window, m_GLContext);
        ImGui_ImplOpenGL2_Init();
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
        /*ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);*/
        ImGui::SetNextWindowSize(ImVec2(width, height), ImGuiCond_Always);
        ImGui::Begin(title, &isActive);
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

        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
    }

    // Handles the updating of window size in ImGui when the SDL window is resized.
    void EsdImGuiLayer::ResizeEvent()
    {
        ImGuiIO& io = ImGui::GetIO();
        int width, height;
        SDL_GetWindowSize(m_Window, &width, &height);
        io.DisplaySize.x = static_cast<float>(width);
        io.DisplaySize.y = static_cast<float>(height);
    }

    // Custom ImGui style.
    void EsdImGuiLayer::DefaultEsdStyle()
    {
        ImGuiStyle& style = ImGui::GetStyle();

        style.WindowPadding = ImVec2(15, 15);
        style.WindowRounding = 5.0f;
        style.FramePadding = ImVec2(6, 6);
        style.FrameRounding = 4.0f;
        style.ItemSpacing = ImVec2(10, 8);
        style.ItemInnerSpacing = ImVec2(8, 6);
        style.IndentSpacing = 25.0f;

        style.ScrollbarSize = 15.0f;
        style.ScrollbarRounding = 9.0f;

        style.GrabMinSize = 5.0f;
        style.GrabRounding = 3.0f;

        style.FrameBorderSize = 0.5f;

        ImVec4 transparent(0.0f, 0.0f, 0.0f, 0.5f);
        ImVec4 white(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 grey(0.2f, 0.2f, 0.2f, 1.0f);
        ImVec4 darkGrey(0.15f, 0.15f, 0.15f, 1.0f);
        ImVec4 black(0.0f, 0.0f, 0.0f, 1.0f);

        style.Colors[ImGuiCol_Text] = white;
        style.Colors[ImGuiCol_TextDisabled] = grey;
        style.Colors[ImGuiCol_WindowBg] = transparent;
        style.Colors[ImGuiCol_ChildBg] = darkGrey;
        style.Colors[ImGuiCol_PopupBg] = black;
        style.Colors[ImGuiCol_Border] = transparent;
        style.Colors[ImGuiCol_BorderShadow] = transparent;
        style.Colors[ImGuiCol_FrameBg] = grey;
        style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.25f, 0.25f, 0.25f, 0.40f);
        style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.35f, 0.35f, 0.35f, 0.67f);
        style.Colors[ImGuiCol_TitleBg] = darkGrey;
        style.Colors[ImGuiCol_TitleBgActive] = darkGrey;
        style.Colors[ImGuiCol_TitleBgCollapsed] = transparent;
        style.Colors[ImGuiCol_MenuBarBg] = darkGrey;
        style.Colors[ImGuiCol_ScrollbarBg] = darkGrey;
        style.Colors[ImGuiCol_ScrollbarGrab] = grey;
        style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.3f, 0.3f, 0.3f, 1.0f);
        style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.4f, 0.4f, 0.4f, 1.0f);
        style.Colors[ImGuiCol_CheckMark] = white;
        style.Colors[ImGuiCol_SliderGrab] = grey;
        style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.4f, 0.4f, 0.4f, 1.0f);
        style.Colors[ImGuiCol_Button] = grey;
        style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.25f, 0.25f, 0.25f, 1.0f);
        style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.35f, 0.35f, 0.35f, 1.0f);
        style.Colors[ImGuiCol_Tab] = darkGrey;
        style.Colors[ImGuiCol_TabHovered] = ImVec4(0.25f, 0.25f, 0.25f, 0.80f);
        style.Colors[ImGuiCol_TabActive] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
        style.Colors[ImGuiCol_TabUnfocused] = darkGrey;
        style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.15f, 0.15f, 0.15f, 1.0f);
        style.Colors[ImGuiCol_Header] = darkGrey;
        style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.25f, 0.25f, 0.25f, 0.80f);
        style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.35f, 0.35f, 0.35f, 1.0f);
    }
}
