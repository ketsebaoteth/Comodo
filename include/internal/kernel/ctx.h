#pragma once

#include <vector>
#include "../media/media_item.h"
#include <string>

struct ProjectContext {
    std::vector<MediaItem> media_list;
    void Add_Media(std::string path, bool is_folder);
    bool show_file_explorer = false;
};

