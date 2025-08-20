#pragma once

#include "imgui.h"
#include <map>
#include <string>
#include <filesystem>
#include <cstdio>

ImTextureID LoadTextureFromFile(const char* filename);

inline bool ImageButtonIcon(const char* filename, ImVec2 button_size = ImVec2(32, 32), ImVec2 image_size = ImVec2(21, 21), const char* tooltip = nullptr) {
    static std::map<std::string, ImTextureID> icon_cache;
    char fullpath[256];
    snprintf(fullpath, sizeof(fullpath), "../src/icon/%s", filename);
    ImTextureID tex_id;
    auto it = icon_cache.find(fullpath);
    if (it == icon_cache.end()) {
        tex_id = LoadTextureFromFile(fullpath);
        icon_cache[fullpath] = tex_id;
    } else {
        tex_id = it->second;
    }
    if (!tex_id) return false;

    ImVec2 pos = ImGui::GetCursorScreenPos();
    bool pressed = ImGui::InvisibleButton(filename, button_size);

    // Set cursor to pointer (hand) if hovered
    if (ImGui::IsItemHovered()) {
        ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
        if (tooltip && tooltip[0]) {
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(10, 8)); // Add padding
            ImGui::BeginTooltip();
            ImGui::TextUnformatted(tooltip);
            ImGui::EndTooltip();
            ImGui::PopStyleVar();
        }
    }

    // Center the image in the button
    ImVec2 image_pos = ImVec2(
        pos.x + (button_size.x - image_size.x) * 0.5f,
        pos.y + (button_size.y - image_size.y) * 0.5f
    );
    ImGui::GetWindowDrawList()->AddImage(
        tex_id,
        image_pos,
        ImVec2(image_pos.x + image_size.x, image_pos.y + image_size.y)
    );

    return pressed;
}

inline void ImageIcon(const char* filename, ImVec2 image_size = ImVec2(21, 21)) {
    static std::map<std::string, ImTextureID> icon_cache;
    char fullpath[256];
    snprintf(fullpath, sizeof(fullpath), "../src/icon/%s", filename);
    ImTextureID tex_id;
    auto it = icon_cache.find(fullpath);
    if (it == icon_cache.end()) {
        tex_id = LoadTextureFromFile(fullpath);
        icon_cache[fullpath] = tex_id;
    } else {
        tex_id = it->second;
    }
    if (!tex_id) return;

    ImGui::Image(tex_id, image_size);
}