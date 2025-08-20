#include "imgui.h"
#include "windows/FileDialoge.h"

void ShowFileExplorer(ProjectContext& ctx){
    ImGui::Begin("Comodo File View",&ctx.show_file_explorer,ImGuiWindowFlags_NoCollapse); // Draggable by default
    ImGui::SetWindowFocus("Comodo File View");
    
    ImGui::End();
}