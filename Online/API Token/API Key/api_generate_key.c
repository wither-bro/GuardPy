#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_api_key(char* output_buffer, size_t buffer_size) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    const size_t key_len = 64; 

    if (buffer_size <= key_len) {
        return;
    }

    srand(time(NULL));

    for (size_t i = 0; i < key_len; i++) {
        output_buffer[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    output_buffer[key_len] = '\0';
}
