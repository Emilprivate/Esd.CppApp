#include "../EsdCppApp.h"

#define WIDTH 1280
#define HEIGHT 720
#define TITLE "Esd.CppApp"

int main(int, char**)
{
    EsdCppApp::EsdApp::StartLayer(TITLE, WIDTH, HEIGHT);

    bool running = true;

    auto myApp = []()
    {
        ImGui::ShowDemoWindow();
    };

    while (running) {
        EsdCppApp::EsdApp::GetEventHandler()->HandleEvent(running);
        EsdCppApp::EsdApp::GetImGuiLayer()->RunFrame(myApp, running);
    }

    EsdCppApp::EsdApp::EndLayer();

    return 0;
}