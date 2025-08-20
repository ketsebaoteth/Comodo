#include <GLFW/glfw3.h>

#include "kernel/utils/init.h"
#include "kernel/ctx.h"

int main() {
    Comodo::GLFWInit();

    GLFWwindow* window = Comodo::CreateWindow(1280, 720, "Comodo");

    Comodo::GUI::Init(*window);

    //set custom theme for imgui
    //TODO: Multiple themes
    Comodo::SetImguiTheme();

    /*
    * project context contains almost everything about the project
    */
    ProjectContext ctx;

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        Comodo::pollEvents();

        Comodo::GUI::NewFrame();
        /*
        * call ui render to start ui
        */
        Comodo::ShowUi(ctx);

        Comodo::GUI::Render(*window);
        Comodo::swapBuffer(*window);
    }

    Comodo::GUI::CleanUp(*window);

    return 0;
}
