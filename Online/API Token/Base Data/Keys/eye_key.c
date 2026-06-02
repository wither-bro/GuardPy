#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define DB_FILE "api_keys_registry.db"
#define MAX_KEY_LENGTH 64

void register_key_to_db(const char* key) {
    FILE* db_file = fopen(DB_FILE, "a");
    if (db_file != NULL) {
        fprintf(db_file, "%s\n", key);
        fclose(db_file);
    }
}

bool verify_key_exists(const char* key) {
    FILE* db_file = fopen(DB_FILE, "r");
    if (db_file == NULL) {
        return false;
    }

    char line[MAX_KEY_LENGTH + 1];
    bool exists = false;

    while (fgets(line, sizeof(line), db_file)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, key) == 0) {
            exists = true;
            break;
        }
    }

    fclose(db_file);
    return exists;
}
