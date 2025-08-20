#include "ui/ui.h"
#include "imgui.h"
#include "utils/buttons.h"
#include "kernel/ctx.h"
#include "windows/FileDialoge.h"

namespace UI{

void ShowMediaPanel(ProjectContext& ctx) {
    if (ImGui::BeginChild("MediaPanelContent", ImVec2(0, 0), false, ImGuiWindowFlags_MenuBar)) {
        if (ImGui::BeginMenuBar()) {
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8, 8));
            if(ImageButtonIcon("file.png", ImVec2(32, 32), ImVec2(21, 21), "Load Media")){
                ImGui::SetNextWindowSize(ImVec2(2000, 1400), ImGuiCond_Always);
                ctx.show_file_explorer = true;
            }
            ImageButtonIcon("folder-plus.png", ImVec2(32, 32), ImVec2(21, 21), "Create Folder");
            ImageButtonIcon("trash.png", ImVec2(32, 32), ImVec2(21, 21), "Delete Selected");
            if (ImageButtonIcon("menu.png", ImVec2(32, 32), ImVec2(21, 21), "Options")) {
                ImGui::OpenPopup("MediaOptionsPopup");
            }

            // Move input to the right
            float menu_width = ImGui::GetWindowWidth();
            float input_width = 180.0f;
            float spacing = ImGui::GetStyle().ItemSpacing.x;
            ImGui::SameLine();
            ImGui::SetCursorPosX(menu_width - input_width - spacing);

            static char search_buf[128] = "";
            ImGui::SetNextItemWidth(input_width);
            ImGui::InputTextWithHint("##search", "Search...", search_buf, sizeof(search_buf));

            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8, 6));
            if (ImGui::BeginPopup("MediaOptionsPopup")) {
                ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(6, 4));
                if (ImGui::BeginMenu("View Style")) {
                    ImGui::MenuItem("Grid");
                    ImGui::MenuItem("List");
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Sort By")) {
                    ImGui::MenuItem("Name");
                    ImGui::MenuItem("Date Modified");
                    ImGui::MenuItem("Size");
                    ImGui::MenuItem("Type");
                    ImGui::MenuItem("Insert Order");
                    ImGui::Separator();
                    ImGui::MenuItem("Ascending");
                    ImGui::MenuItem("Descending");
                    ImGui::EndMenu();
                }
                ImGui::PopStyleVar();
                ImGui::EndPopup();
            }
            ImGui::PopStyleVar();
            ImGui::PopStyleVar();
            ImGui::EndMenuBar();
        }
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(12, 8)); // Adjust as needed
        ImGui::BeginChild("MediaList", ImVec2(0, 0), true, ImGuiWindowFlags_NoScrollbar);
        
        for (size_t i = 0; i < ctx.media_list.size(); ++i) {
        const auto& item = ctx.media_list[i];
        if (item.is_folder) {
            ShowFolderIcon(item);
        } else {
            ShowFileIcon(item);
        }
        if (i != ctx.media_list.size() - 1) {
            ImGui::SameLine();
        }
}
        ImGui::EndChild();
        ImGui::PopStyleVar();
    }
    ImGui::EndChild();
}

void ShowFolderIcon(const MediaItem& item) {
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(4, 4));
    std::string child_id = "Folder" + item.name;
    ImVec2 child_size(150, 150);
    ImGui::BeginChild(child_id.c_str(), child_size, true, ImGuiWindowFlags_NoScrollbar);

    // Center the image horizontally
    ImGui::SetCursorPosX(-100.0f);
    ImageIcon("folder.png", ImVec2(350, 100)); // Adjust size as needed

    // Center the text horizontally
    ImVec2 text_size = ImGui::CalcTextSize(item.name.c_str());
    ImGui::SetCursorPosX((child_size.x - text_size.x) * 0.5f);
    ImGui::Text("%s", item.name.c_str());

    ImGui::EndChild();
    ImGui::PopStyleVar();

    // Check if the folder child is hovered
    if (ImGui::IsItemHovered()) {
        ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
    }
}

void ShowFileIcon(const MediaItem& item) {
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(4, 4));
    std::string child_id = "File" + item.name;
    ImVec2 child_size(150, 150);
    ImGui::BeginChild(child_id.c_str(), child_size, true, ImGuiWindowFlags_NoScrollbar);

    // Center the image horizontally
    ImGui::SetCursorPosX(25.0f);

    // Center the text horizontally
    ImVec2 text_size = ImGui::CalcTextSize(item.name.c_str());
    ImGui::SetCursorPosX((child_size.x - text_size.x) * 0.5f);
    ImGui::Text("%s", item.name.c_str());

    ImGui::EndChild();
    ImGui::PopStyleVar();

    // Check if the file child is hovered
    if (ImGui::IsItemHovered()) {
        ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
    }
}
}
