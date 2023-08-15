#pragma once
#include <string>
#include "ImGuiLayer.h"
#include "EventHandler.h"

namespace EsdCppApp {

    class EsdApp {
    public:
        static void StartLayer(const std::string& title, int width, int height);
        static void EndLayer();

        static ImGuiLayer* GetImGuiLayer();
        static EventHandler* GetEventHandler();
    };
}
