#ifndef HTTP_REQUEST_HANDLER_H
#define HTTP_REQUEST_HANDLER_H

#include <string>
#include <vector>
#include <map>

class HTTPTraffic {
private:
    std::string host;
    int port;

public:
    HTTPTraffic(const std::string& target_host, int target_port) 
        : host(target_host), port(target_port) {}

    void send_request(const std::string& method, const std::string& path, const std::string& body) {
        std::string request = method + " " + path + " HTTP/1.1\r\n" +
                              "Host: " + host + "\r\n" +
                              "Content-Length: " + std::to_string(body.length()) + "\r\n" +
                              "Connection: close\r\n\r\n" +
                              body;
        
        execute_transfer(request);
    }

private:
    void execute_transfer(const std::string& raw_data) {
    }
};

#endif
