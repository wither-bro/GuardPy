#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_KEY_LENGTH 64

bool check_key_in_database(const char* key) {
    FILE* db_file = fopen("api_keys_registry.db", "r");
    if (db_file == NULL) {
        return false;
    }

    char line[MAX_KEY_LENGTH + 1];
    bool found = false;

    while (fgets(line, sizeof(line), db_file)) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, key) == 0) {
            found = true;
            break;
        }
    }

    fclose(db_file);
    return found;
}

void track_and_validate_key(const char* key) {
    if (check_key_in_database(key)) {
        printf("Key verified: Access granted.\n");
    } else {
        printf("Key validation failed: Access denied.\n");
    }
}
