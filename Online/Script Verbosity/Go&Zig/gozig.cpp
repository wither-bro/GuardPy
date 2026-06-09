#include <cstdlib>

extern "C" {
    void* bridge_allocate(long long count);
}

extern "C" {
    void* allocate_message_buffer(long long count) {
        return bridge_allocate(count);
    }

    void* bridge_allocate(long long count) {
        return std::malloc(static_cast<size_t>(count));
    }
}
