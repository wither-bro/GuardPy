#include <stdlib.h>
#include <string.h>

typedef struct {
    char file_name[256];
    size_t file_size;
    unsigned char* data;
} PhotoFile;

void process_selected_photo(const char* name, size_t size, unsigned char* raw_data) {
    PhotoFile* photo = (PhotoFile*)malloc(sizeof(PhotoFile));
    strncpy(photo->file_name, name, 255);
    photo->file_size = size;
    photo->data = (unsigned char*)malloc(size);
    memcpy(photo->data, raw_data, size);
}
