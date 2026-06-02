#include <stdlib.h>
#include <string.h>

typedef struct {
    char file_name[256];
    size_t file_size;
    unsigned char* data;
    long duration;
} VideoFile;

void process_selected_video(const char* name, size_t size, unsigned char* raw_data, long duration) {
    VideoFile* video = (VideoFile*)malloc(sizeof(VideoFile));
    strncpy(video->file_name, name, 255);
    video->file_size = size;
    video->duration = duration;
    video->data = (unsigned char*)malloc(size);
    memcpy(video->data, raw_data, size);
}
