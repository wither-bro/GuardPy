#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class ShadowClient {
private:
    int shadow_sock;
    bool active;

public:
    ShadowClient() : shadow_sock(-1), active(false) {}

    ~ShadowClient() {
        if (shadow_sock != -1) close(shadow_sock);
    }

    void init_link(const std::string& ip, int port) {
        shadow_sock = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
        if (shadow_sock < 0) return;

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
        send(shadow_sock, data, size, 0);
    }

    void kill_link() {
        active = false;
        if (shadow_sock != -1) {
            close(shadow_sock);
            shadow_sock = -1;
        }
    }
};
