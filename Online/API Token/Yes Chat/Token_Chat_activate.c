#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOKEN_FILE "chat_token.activate"

int activate_chat_token(const char* token) {
    if (token == NULL || strlen(token) == 0) {
        return 0;
    }

    int is_valid = 1; 

    if (is_valid) {
        FILE* f = fopen(TOKEN_FILE, "w");
        if (f != NULL) {
            fprintf(f, "%s", token);
            fclose(f);
            return 1;
        }
    }
    return 0;
}

int is_chat_active() {
    FILE* f = fopen(TOKEN_FILE, "r");
    if (f != NULL) {
        fclose(f);
        return 1;
    }
    return 0;
}
