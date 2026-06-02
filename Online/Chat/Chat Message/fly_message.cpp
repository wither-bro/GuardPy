#include <iostream>
#include <vector>
#include <cstring>

extern "C" {
    void handle_incoming_message(char* sender, char* text, long long len);
}

extern "C" {
    void handle_incoming_message(char* sender, char* text, long long len) {
        if (len <= 0 || len > 20000000) {
            return;
        }

        char* local_sender = new char[32];
        std::memcpy(local_sender, sender, 32);

        char* local_text = new char[len];
        std::memcpy(local_text, text, len);

        delete[] local_sender;
        delete[] local_text;
    }
}
