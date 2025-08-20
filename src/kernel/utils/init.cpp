#include "kernel/utils/init.h"
#include <iostream>
#include "theme/theme.h"
#include "ui/ui.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <string>


namespace Comodo{
    void GLFWInit(){
        // Init GLFW
        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW\n";
            return;
        }

        // OpenGL version hint
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
    }

    GLFWwindow* CreateWindow(int width,int height,std::string title){
         // Create window
        GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!window) {
            std::cerr << "Failed to create GLFW window\n";
            glfwTerminate();
            return nullptr;
        }
        glfwMakeContextCurrent(window);
        glfwSwapInterval(1); // Enable vsync
        return window;
    }

    void SetImguiTheme(){
        Theme::SetTheme();
    }
    void ShowUi(ProjectContext& ctx){
       UI::Show(ctx);
    }
    void pollEvents(){
        glfwPollEvents();
    }
    void swapBuffer(GLFWwindow &window){
        glfwSwapBuffers(&window);
    }
    namespace GUI {
        void NewFrame() {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
        }
        void Init(GLFWwindow &window) {
            // Setup ImGui context
            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            ImGui_ImplGlfw_InitForOpenGL(&window, true);
            ImGui_ImplOpenGL3_Init("#version 330");
        }
        void Render(GLFWwindow &window) {
            ImGui::Render();
            int display_w, display_h;
            glfwGetFramebufferSize(&window, &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        }
        void CleanUp(GLFWwindow &window) {
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext();
            glfwDestroyWindow(&window);
            glfwTerminate();
        }
    }
};