#ifndef ONLINE_CORE_H
#define ONLINE_CORE_H

#include "data_online.cpp"
#include "traffic.cpp"

class OnlineCore {
private:
    DataOnlineTransfer transfer;
    TrafficController traffic;

public:
    void init(const std::string& ip, int port) {
        transfer.connect_to_node(ip, port);
    }

    void handle_data(const char* buffer, size_t size) {
        if (traffic.is_healthy()) {
            traffic.process_stream(buffer, size);
            std::vector<char> data(buffer, buffer + size);
            transfer.transmit(data);
        }
    }

    void shutdown() {
        traffic.emergency_stop();
    }
};

#endif
