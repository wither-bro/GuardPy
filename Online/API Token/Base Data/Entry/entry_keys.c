#include <stdio.h>

#define ENTRY_LOG "entry_keys.log"

void record_generated_key(const char* key) {
    FILE* log_file = fopen(ENTRY_LOG, "a");
    if (log_file != NULL) {
        fprintf(log_file, "Generated Key: %s\n", key);
        fclose(log_file);
    }
}
