#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class DataOnlineTransfer {
private:
    int sock;
    bool is_connected;

    void secure_shutdown() {
        if (is_connected) {
            close(sock);
            is_connected = false;
        }
    }

public:
    DataOnlineTransfer() : sock(-1), is_connected(false) {}

    ~DataOnlineTransfer() {
        secure_shutdown();
    }

    void connect_to_node(const std::string& ip, int port) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) throw std::runtime_error("CRITICAL: Socket creation failed");

        struct sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &serv_addr.sin_addr);

        if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
            secure_shutdown();
            throw std::runtime_error("CRITICAL: Connection link failure - Aborting");
        }
        is_connected = true;
    }

    void transmit(const std::vector<char>& data) {
        if (!is_connected) return;

        ssize_t sent = send(sock, data.data(), data.size(), 0);
        if (sent != static_cast<ssize_t>(data.size())) {
            secure_shutdown();
            throw std::runtime_error("CRITICAL: Data transmission drop - Network purge initiated");
        }
    }
};
