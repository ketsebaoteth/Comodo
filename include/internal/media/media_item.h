#pragma once

#include <string>
#include <vector>

struct MediaItem {
    std::string name;
    std::string path;
    bool is_folder;
    bool is_favorite;
    bool is_selected;
    bool is_audio;
    std::vector<std::string> tags;
    std::vector<MediaItem> children; // Only used if is_folder == true
};