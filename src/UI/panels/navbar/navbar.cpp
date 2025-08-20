#include "imgui.h"
#include "ui/ui.h"
#include "kernel/shortcuts/shortcut.h"

namespace UI{
void ShowNavbarPanel(){
    if(ImGui::BeginMainMenuBar()){
        if (ImGui::BeginMenu("File")) {
            ImGui::MenuItem("New", SHORTCUT_STRINGS[NEW_PR]);
            ImGui::MenuItem("Open", SHORTCUT_STRINGS[OPEN_PR]);
            if(ImGui::BeginMenu("Open Recent")){
                ImGui::MenuItem("File 1");
                ImGui::MenuItem("File 2");
                ImGui::MenuItem("File 3");
                ImGui::EndMenu();
            }
            ImGui::Separator();
            ImGui::MenuItem("Save", "Ctrl+S");
            ImGui::MenuItem("Save As", "Ctrl+Shift+S");
            ImGui::MenuItem("View in Explorer");
            ImGui::Separator();
            ImGui::MenuItem("OpenTimelineIO Import");
            ImGui::MenuItem("OpenTimelineIO Export");
            ImGui::Separator();
            ImGui::MenuItem("Exit", "Alt+F4");
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Edit")) {
            ImGui::MenuItem("Undo","CTRL+Z");
            ImGui::MenuItem("Redo","CTRL+SHIFT+Z");
            ImGui::Separator();
            ImGui::MenuItem("Copy","CTRL+C");
            ImGui::MenuItem("Paste","CTRL+V");
            ImGui::Separator();
            ImGui::MenuItem("Preferances");
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("View")) {
            ImGui::MenuItem("Toggle Metering");
            ImGui::MenuItem("Fullscreen");
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Project")) {
            ImGui::MenuItem("Settings");
            ImGui::MenuItem("Export");
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
    }
}