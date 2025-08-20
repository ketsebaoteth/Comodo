#include "ui/ui.h"
#include "imgui.h"
#include "windows/FileDialoge.h"

namespace UI{
    void Show(ProjectContext& ctx) {
    UI::ShowNavbarPanel();

    ImVec2 viewport_pos = ImGui::GetMainViewport()->Pos;
    ImVec2 viewport_size = ImGui::GetMainViewport()->Size;
    float menu_bar_height = ImGui::GetFrameHeight();

    ImGui::SetNextWindowPos(ImVec2(viewport_pos.x, viewport_pos.y + menu_bar_height), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(viewport_size.x, viewport_size.y - menu_bar_height), ImGuiCond_Always);

    ImGui::Begin("Main Panel", nullptr,
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoScrollWithMouse |
        ImGuiWindowFlags_NoTitleBar
    );

    // Splitter settings
    static float top_height = 0.5f; // Fraction of height for top row
    static float media_width = 0.0f; // Will be set as percent on first frame
    static float sequencer_width = 0.0f; // Will be set as percent on first frame
    float splitter_hitbox = 10.0f;   // Wide hitbox for easy grabbing
    float splitter_visual = 1.0f;    // Thin visual line
    float min_panel_height = 100.0f;
    float min_panel_width = 100.0f;

    float total_height = ImGui::GetContentRegionAvail().y;
    float total_width = ImGui::GetContentRegionAvail().x;

    // Set initial widths as percent of total width
    static bool first_frame = true;
    if (first_frame) {
        media_width = total_width * 0.3f;      // 30% for media panel
        sequencer_width = total_width * 0.7f;  // 70% for sequencer panel
        first_frame = false;
    }

    // Calculate heights for top and bottom rows
    float top_row_height = top_height * (total_height - splitter_visual);
    float bottom_row_height = total_height - top_row_height - splitter_visual;

    if (top_row_height < min_panel_height) top_row_height = min_panel_height;
    if (bottom_row_height < min_panel_height) bottom_row_height = min_panel_height;

    // Remove window padding for all panels
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec2 old_padding = style.WindowPadding;
    style.WindowPadding = ImVec2(0, 0);

    // --- Top Row: Media | Preview ---
    ImGui::BeginChild("TopRow", ImVec2(total_width, top_row_height), false, ImGuiWindowFlags_NoScrollbar);

    if (media_width < min_panel_width) media_width = min_panel_width;
    if (media_width > total_width - min_panel_width - splitter_visual) media_width = total_width - min_panel_width - splitter_visual;

    ImGui::BeginChild("MediaPanel", ImVec2(media_width, top_row_height), true, ImGuiWindowFlags_NoScrollbar);
    ShowMediaPanel(ctx);
    ImGui::EndChild();

    // Vertical splitter (Top) - keep panels close, wide hitbox, thin visual
    ImGui::SameLine(0.0f, 0.0f);
    float splitter_overlap = splitter_hitbox - splitter_visual;
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() - splitter_overlap * 0.5f);

    ImGui::PushID("VSplitterTop");
    ImGui::InvisibleButton("VSplitterTop", ImVec2(splitter_hitbox, top_row_height));
    if (ImGui::IsItemActive() && ImGui::IsMouseDragging(ImGuiMouseButton_Left)) {
        media_width += ImGui::GetIO().MouseDelta.x;
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetMouseCursor(ImGuiMouseCursor_ResizeEW);
    }
    ImGui::PopID();

    // Draw thin visual splitter centered in the hitbox
    ImVec2 vsplitter_min = ImGui::GetItemRectMin();
    ImVec2 vsplitter_max = ImGui::GetItemRectMax();
    float vsplitter_x = (vsplitter_min.x + vsplitter_max.x) * 0.5f - splitter_visual * 0.5f;
    ImGui::GetWindowDrawList()->AddRectFilled(
        ImVec2(vsplitter_x, vsplitter_min.y),
        ImVec2(vsplitter_x + splitter_visual, vsplitter_max.y),
        IM_COL32(80, 80, 80, 80)
    );

    ImGui::SameLine(0.0f, 0.0f);

    ImGui::BeginChild("PreviewPanel", ImVec2(0, top_row_height), true, ImGuiWindowFlags_NoScrollbar);
    UI::ShowPreviewPanel();
    ImGui::EndChild();

    ImGui::EndChild();

    // --- Horizontal splitter ---
    float hsplitter_overlap = splitter_hitbox - splitter_visual;
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() - hsplitter_overlap * 0.5f);

    ImGui::PushID("HSplitter");
    ImGui::InvisibleButton("HSplitter", ImVec2(total_width, splitter_hitbox));
    if (ImGui::IsItemActive() && ImGui::IsMouseDragging(ImGuiMouseButton_Left)) {
        float delta = ImGui::GetIO().MouseDelta.y / (total_height - splitter_visual);
        top_height += delta;
        if (top_height < min_panel_height / total_height) top_height = min_panel_height / total_height;
        if (top_height > 1.0f - min_panel_height / total_height) top_height = 1.0f - min_panel_height / total_height;
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetMouseCursor(ImGuiMouseCursor_ResizeNS);
    }
    ImGui::PopID();

    ImVec2 hsplitter_min = ImGui::GetItemRectMin();
    ImVec2 hsplitter_max = ImGui::GetItemRectMax();
    float hsplitter_y = (hsplitter_min.y + hsplitter_max.y) * 0.5f - splitter_visual * 0.5f;
    ImGui::GetWindowDrawList()->AddRectFilled(
        ImVec2(hsplitter_min.x, hsplitter_y),
        ImVec2(hsplitter_max.x, hsplitter_y + splitter_visual),
        IM_COL32(80, 80, 80, 80)
    );

    // --- Bottom Row: Sequencer | Properties ---
    ImGui::BeginChild("BottomRow", ImVec2(total_width, bottom_row_height), false, ImGuiWindowFlags_NoScrollbar);

    if (sequencer_width < min_panel_width) sequencer_width = min_panel_width;
    if (sequencer_width > total_width - min_panel_width - splitter_visual) sequencer_width = total_width - min_panel_width - splitter_visual;

    ImGui::BeginChild("SequencerPanel", ImVec2(sequencer_width, bottom_row_height), true, ImGuiWindowFlags_NoScrollbar);
    UI::ShowSequencerPanel();
    ImGui::EndChild();

    ImGui::SameLine(0.0f, 0.0f);
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() - splitter_overlap * 0.5f);

    // Vertical splitter (Bottom)
    ImGui::PushID("VSplitterBottom");
    ImGui::InvisibleButton("VSplitterBottom", ImVec2(splitter_hitbox, bottom_row_height));
    if (ImGui::IsItemActive() && ImGui::IsMouseDragging(ImGuiMouseButton_Left)) {
        sequencer_width += ImGui::GetIO().MouseDelta.x;
    }
    if (ImGui::IsItemHovered()) {
        ImGui::SetMouseCursor(ImGuiMouseCursor_ResizeEW);
    }
    ImGui::PopID();

    ImVec2 vsplitter2_min = ImGui::GetItemRectMin();
    ImVec2 vsplitter2_max = ImGui::GetItemRectMax();
    float vsplitter2_x = (vsplitter2_min.x + vsplitter2_max.x) * 0.5f - splitter_visual * 0.5f;
    ImGui::GetWindowDrawList()->AddRectFilled(
        ImVec2(vsplitter2_x, vsplitter2_min.y),
        ImVec2(vsplitter2_x + splitter_visual, vsplitter2_max.y),
        IM_COL32(80, 80, 80, 80)
    );

    ImGui::SameLine(0.0f, 0.0f);

    ImGui::BeginChild("PropertiesPanel", ImVec2(0, bottom_row_height), true, ImGuiWindowFlags_NoScrollbar);
    UI::ShowPropertiesPanel();
    ImGui::EndChild();

    ImGui::EndChild();

    ImGui::End();

    // Restore previous padding
    style.WindowPadding = old_padding;

    //show file explorer if show_file_explorer 
    if(ctx.show_file_explorer) {
        ShowFileExplorer(ctx);
    }
}
}

