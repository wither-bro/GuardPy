#include <iostream>

extern "C" {
    void* allocate_message_buffer(long long count) {
        return new char[count * 1024];
    }
}
