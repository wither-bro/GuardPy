extern "C" {
    void* bridge_allocate(long long count);
}

extern "C" {
    void* allocate_message_buffer(long long count) {
        return bridge_allocate(count);
    }
}
