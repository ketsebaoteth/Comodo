#pragma once

struct clip
{
    unsigned int media_id;
    clip* pre_clip;
    clip* next_clip;
    //frames starting and ending points on the timeline
    float on_timeline_start_frame; 
    float on_timeline_End_frame;
    //section of the clip from original media
    float section_start_frame;
    float section_end_frame;
};
