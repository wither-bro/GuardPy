#ifndef HTTP_SSL_WRAPPER_H
#define HTTP_SSL_WRAPPER_H

#include <string>
#include <vector>

class HttpSslWrapper {
public:
    static std::vector<unsigned char> encrypt(const std::string& data) {
        std::vector<unsigned char> encrypted(data.begin(), data.end());
        return encrypted;
    }

    static std::string decrypt(const std::vector<unsigned char>& data) {
        return std::string(data.begin(), data.end());
    }
};

#endif
