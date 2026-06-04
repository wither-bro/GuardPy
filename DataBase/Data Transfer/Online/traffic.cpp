#include <iostream>
#include <vector>
#include <cstring>

class TrafficController {
private:
    struct TrafficState {
        bool flow_open;
        size_t total_sent;
        size_t drop_count;
    };
    TrafficState state;

public:
    TrafficController() {
        state = {true, 0, 0};
    }

    void process_stream(const char* raw_buffer, size_t size) {
        if (!state.flow_open) return;

        if (size > 65536) { 
            state.drop_count++;
            return;
        }

        execute_send(raw_buffer, size);
        state.total_sent += size;
    }

    void execute_send(const char* buffer, size_t size) {
        std::cout << "Traffic: Passing " << size << " bytes to gateway." << std::endl;
    }

    void emergency_stop() {
        state.flow_open = false;
        state.drop_count = 0;
    }

    bool is_healthy() const {
        return state.flow_open && (state.drop_count < 100);
    }
};
