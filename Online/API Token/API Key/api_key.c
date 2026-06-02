#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256

typedef struct {
    char key_value[MAX_KEY_LENGTH];
    int is_verified;
} APIKey;

void set_api_key(const char* input_key) {
    if (input_key == NULL || strlen(input_key) == 0) {
        return;
    }

    FILE* secret_file = fopen("guardpy_secret.key", "w");
    if (secret_file != NULL) {
        fprintf(secret_file, "%s", input_key);
        fclose(secret_file);
    }
}

int load_and_verify_key(APIKey* key_struct) {
    FILE* secret_file = fopen("guardpy_secret.key", "r");
    if (secret_file == NULL) {
        key_struct->is_verified = 0;
        return 0;
    }

    if (fgets(key_struct->key_value, MAX_KEY_LENGTH, secret_file) != NULL) {
        key_struct->is_verified = 1;
    } else {
        key_struct->is_verified = 0;
    }
    
    fclose(secret_file);
    return key_struct->is_verified;
}
