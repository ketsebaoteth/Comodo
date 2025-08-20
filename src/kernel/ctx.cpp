#include "kernel/ctx.h"

//Add Item to Media List
void ProjectContext::Add_Media(std::string path, bool is_folder=false){
    MediaItem item;
    item.path = path;
    item.is_folder = is_folder;
    media_list.push_back(item);
}