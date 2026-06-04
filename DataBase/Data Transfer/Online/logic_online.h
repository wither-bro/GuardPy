#ifndef LOGIC_ONLINE_H
#define LOGIC_ONLINE_H

#include "online_core.h"
#include <mutex>

class LogicOnline {
private:
    OnlineCore core;
    std::mutex mtx;

public:
    void execute_logic(const char* data, size_t size) {
        std::lock_guard<std::mutex> lock(mtx);
        core.handle_data(data, size);
    }

    void initialize_node(const std::string& ip, int port) {
        core.init(ip, port);
    }

    void force_terminate() {
        core.shutdown();
    }
};

#endif
