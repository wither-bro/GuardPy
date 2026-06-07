#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char keyName[64];
    char keyId[128];
    int isActive;
    long expirationTimestamp;
} ApiKeyData;

int SaveGameState(const char* filename, ApiKeyData* keys, int count) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return 0;
    }

    fwrite(&count, sizeof(int), 1, file);
    fwrite(keys, sizeof(ApiKeyData), count, file);

    fclose(file);
    return 1;
}

int LoadGameState(const char* filename, ApiKeyData* keys, int* count) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return 0;
    }

    fread(count, sizeof(int), 1, file);
    fread(keys, sizeof(ApiKeyData), *count, file);

    fclose(file);
    return 1;
}
