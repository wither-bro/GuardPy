#ifndef HTTP_CONNECTION_POOL_H
#define HTTP_CONNECTION_POOL_H

#include <vector>
#include <mutex>
#include <memory>

class HttpConnectionPool {
private:
    struct Connection {
        int sock;
        bool busy;
    };

    std::vector<Connection> pool;
    std::mutex mtx;

public:
    HttpConnectionPool(size_t size) {
        for (size_t i = 0; i < size; ++i) {
            pool.push_back({-1, false});
        }
    }

    int acquire() {
        std::lock_guard<std::mutex> lock(mtx);
        for (auto& conn : pool) {
            if (!conn.busy) {
                conn.busy = true;
                return conn.sock;
            }
        }
        return -1;
    }

    void release(int sock) {
        std::lock_guard<std::mutex> lock(mtx);
        for (auto& conn : pool) {
            if (conn.sock == sock) {
                conn.busy = false;
                break;
            }
        }
    }
};

#endif
