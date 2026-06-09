#include <stdio.h>
#include <string.h>

#define NO_CHAT_TOKEN_FILE "no_chat_session.token"

void activate_no_chat_api(const char* token) {
    if (token == NULL || strlen(token) == 0) {
        return;
    }

    FILE* f = fopen(NO_CHAT_TOKEN_FILE, "w");
    if (f != NULL) {
        fprintf(f, "%s", token);
        fclose(f);
    }
}

int is_no_chat_active() {
    FILE* f = fopen(NO_CHAT_TOKEN_FILE, "r");
    if (f != NULL) {
        fclose(f);
        return 1;
    }
    return 0;
}
