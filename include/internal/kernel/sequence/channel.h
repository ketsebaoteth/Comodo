#pragma once
#include "kernel/sequence/clip.h"

struct channel{
    unsigned int ID;
    bool Mute = false;
    bool effects = true;
    bool visible = true;
    clip Root_Clip;
};