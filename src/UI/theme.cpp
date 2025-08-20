#include "theme/theme.h"
#include "imgui.h"

namespace Theme{
   void SetTheme(){
    // Setup ImGui style
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    
    io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\segoeui.ttf", 20.0f);
    io.FontGlobalScale = 1.3f;

    ImGui::GetStyle().ScaleAllSizes(1.6f); // Scale all widget sizes

    ImGui::StyleColorsDark();
            // Custom black/gray theme
            ImGuiStyle& style = ImGui::GetStyle();
            style.WindowRounding = 6.0f;
            style.FrameRounding = 4.0f;
            style.ScrollbarRounding = 6.0f;
            style.GrabRounding = 4.0f;
            style.FrameBorderSize = 1.0f;
            style.WindowBorderSize = 1.0f;
            style.WindowPadding = ImVec2(12, 10);
            style.FramePadding = ImVec2(8, 4);
            style.ItemSpacing = ImVec2(8, 6);
            style.Colors[ImGuiCol_WindowBg]         = ImVec4(0.07f, 0.08f, 0.10f, 1.00f); // almost black
            style.Colors[ImGuiCol_ChildBg]          = ImVec4(0.10f, 0.11f, 0.13f, 1.00f);
            style.Colors[ImGuiCol_Border]           = ImVec4(0.22f, 0.23f, 0.25f, 0.45f); // subtle gray
            style.Colors[ImGuiCol_BorderShadow]     = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
            style.Colors[ImGuiCol_FrameBg]          = ImVec4(0.13f, 0.14f, 0.16f, 1.00f);
            style.Colors[ImGuiCol_FrameBgHovered]   = ImVec4(0.18f, 0.19f, 0.21f, 1.00f);
            style.Colors[ImGuiCol_FrameBgActive]    = ImVec4(0.20f, 0.21f, 0.23f, 1.00f);
            style.Colors[ImGuiCol_TitleBg]          = ImVec4(0.10f, 0.11f, 0.13f, 1.00f);
            style.Colors[ImGuiCol_TitleBgActive]    = ImVec4(0.13f, 0.14f, 0.16f, 1.00f);
            style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.07f, 0.08f, 0.10f, 1.00f);
            style.Colors[ImGuiCol_MenuBarBg]        = ImVec4(0.10f, 0.11f, 0.13f, 1.00f);
            style.Colors[ImGuiCol_PopupBg]          = ImVec4(0.10f, 0.11f, 0.13f, 0.98f);
            style.Colors[ImGuiCol_Button]           = ImVec4(0.16f, 0.17f, 0.19f, 1.00f);
            style.Colors[ImGuiCol_ButtonHovered]    = ImVec4(0.22f, 0.23f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_ButtonActive]     = ImVec4(0.18f, 0.19f, 0.21f, 1.00f);
            style.Colors[ImGuiCol_Header]           = ImVec4(0.16f, 0.17f, 0.19f, 1.00f);
            style.Colors[ImGuiCol_HeaderHovered]    = ImVec4(0.22f, 0.23f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_HeaderActive]     = ImVec4(0.18f, 0.19f, 0.21f, 1.00f);
            style.Colors[ImGuiCol_Separator]        = ImVec4(0.22f, 0.23f, 0.25f, 0.45f);
            style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.22f, 0.23f, 0.25f, 0.75f);
            style.Colors[ImGuiCol_SeparatorActive]  = ImVec4(0.22f, 0.23f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarBg]      = ImVec4(0.10f, 0.11f, 0.13f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarGrab]    = ImVec4(0.16f, 0.17f, 0.19f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.22f, 0.23f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarGrabActive]  = ImVec4(0.18f, 0.19f, 0.21f, 1.00f);
            style.Colors[ImGuiCol_CheckMark]        = ImVec4(0.36f, 0.37f, 0.39f, 1.00f);
            style.Colors[ImGuiCol_SliderGrab]       = ImVec4(0.22f, 0.23f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.36f, 0.37f, 0.39f, 1.00f);
            style.Colors[ImGuiCol_Text]             = ImVec4(0.87f, 0.88f, 0.90f, 1.00f);
            style.Colors[ImGuiCol_TextDisabled]     = ImVec4(0.50f, 0.51f, 0.53f, 1.00f);
            style.Colors[ImGuiCol_Tab]              = ImVec4(0.13f, 0.14f, 0.16f, 1.00f);
            style.Colors[ImGuiCol_TabHovered]       = ImVec4(0.22f, 0.23f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_TabActive]        = ImVec4(0.16f, 0.17f, 0.19f, 1.00f);
            style.Colors[ImGuiCol_TabUnfocused]     = ImVec4(0.10f, 0.11f, 0.13f, 1.00f);
            style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.13f, 0.14f, 0.16f, 1.00f);
    } 
}
