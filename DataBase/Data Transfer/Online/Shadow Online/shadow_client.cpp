#include <iostream>
#include <vector>
#include <string>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

class ShadowClient {
private:
#ifdef _WIN32
    SOCKET shadow_sock;
#else
    int shadow_sock;
#endif
    bool active;
#ifdef _WIN32
    static bool wsaInitialized;
    static void ensureWSA() {
        if (!wsaInitialized) {
            WSADATA wsaData;
            WSAStartup(MAKEWORD(2, 2), &wsaData);
            wsaInitialized = true;
        }
    }
#endif

public:
    ShadowClient() : shadow_sock(
#ifdef _WIN32
        INVALID_SOCKET
#else
        -1
#endif
    ), active(false) {}

    ~ShadowClient() {
        if (shadow_sock != -1) {
#ifdef _WIN32
            closesocket(shadow_sock);
#else
            close(shadow_sock);
#endif
        }
    }

    void init_link(const std::string& ip, int port) {
#ifdef _WIN32
        ensureWSA();
#endif
        shadow_sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
#ifdef _WIN32
        if (shadow_sock == INVALID_SOCKET) return;
#else
        if (shadow_sock < 0) return;
#endif

        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);

        if (connect(shadow_sock, (struct sockaddr*)&addr, sizeof(addr)) == 0) {
            active = true;
        }
    }

    void push_shadow(const unsigned char* data, size_t size) {
        if (!active) return;
#ifdef _WIN32
        send(shadow_sock, reinterpret_cast<const char*>(data), static_cast<int>(size), 0);
#else
        send(shadow_sock, data, size, 0);
#endif
    }

    void kill_link() {
        active = false;
#ifdef _WIN32
        if (shadow_sock != INVALID_SOCKET) {
            closesocket(shadow_sock);
            shadow_sock = INVALID_SOCKET;
        }
#else
        if (shadow_sock != -1) {
            close(shadow_sock);
            shadow_sock = -1;
        }
#endif
    }
};

#ifdef _WIN32
bool ShadowClient::wsaInitialized = false;
#endif
