#pragma once
#include "kernel/ctx.h"

namespace UI{
    void Show(ProjectContext& ctx);
    void ShowMediaPanel(ProjectContext& ctx);
    void ShowPreviewPanel();
    void ShowNavbarPanel();
    void ShowSequencerPanel();
    void ShowPropertiesPanel();
    void ShowFolderIcon(const MediaItem& item);
    void ShowFileIcon(const MediaItem& item);
}
