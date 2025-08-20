#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include "kernel/ctx.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

void GLFW_Init();

namespace Comodo {
    void GLFWInit();
    GLFWwindow* CreateWindow(int width, int height, std::string title);
    void SetImguiTheme();
    void ShowUi(ProjectContext &ctx);

    //glfw
    void pollEvents();
    void swapBuffer(GLFWwindow &window);

    //imgui staff
    namespace GUI {
        void Init(GLFWwindow &window);
        void Render(GLFWwindow &window);
        void CleanUp(GLFWwindow &window);
        void NewFrame();
    }
}