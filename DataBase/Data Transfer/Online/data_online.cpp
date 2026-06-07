#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

class DataOnlineTransfer {
private:
#ifdef _WIN32
    SOCKET sock;
    static bool wsaInitialized;
    static void ensureWSA() {
        if (!wsaInitialized) {
            WSADATA wsaData;
            WSAStartup(MAKEWORD(2, 2), &wsaData);
            wsaInitialized = true;
        }
    }
#else
    int sock;
#endif
    bool is_connected;

    void secure_shutdown() {
        if (is_connected) {
#ifdef _WIN32
            closesocket(sock);
#else
            close(sock);
#endif
            is_connected = false;
        }
    }

public:
    DataOnlineTransfer()
#ifdef _WIN32
        : sock(INVALID_SOCKET), is_connected(false) {}
#else
        : sock(-1), is_connected(false) {}
#endif

    ~DataOnlineTransfer() {
        secure_shutdown();
    }

    void connect_to_node(const std::string& ip, int port) {
#ifdef _WIN32
        ensureWSA();
#endif
        sock = socket(AF_INET, SOCK_STREAM, 0);
#ifdef _WIN32
        if (sock == INVALID_SOCKET) throw std::runtime_error("CRITICAL: Socket creation failed");
#else
        if (sock < 0) throw std::runtime_error("CRITICAL: Socket creation failed");
#endif

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

#ifdef _WIN32
        int sent = send(sock, data.data(), static_cast<int>(data.size()), 0);
#else
        ssize_t sent = send(sock, data.data(), data.size(), 0);
#endif
        if (sent != static_cast<int>(data.size())) {
            secure_shutdown();
            throw std::runtime_error("CRITICAL: Data transmission drop - Network purge initiated");
        }
    }
};

#ifdef _WIN32
bool DataOnlineTransfer::wsaInitialized = false;
#endif
