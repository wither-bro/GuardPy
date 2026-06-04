#ifndef HTTP_PARSER_H
#define HTTP_PARSER_H

#include <string>
#include <vector>
#include <sstream>

class HttpParser {
public:
    struct Response {
        int status_code;
        std::string body;
    };

    static Response parse(const std::string& raw_response) {
        Response resp = {0, ""};
        std::istringstream stream(raw_response);
        std::string line;

        if (std::getline(stream, line)) {
            size_t first_space = line.find(' ');
            size_t second_space = line.find(' ', first_space + 1);
            if (first_space != std::string::npos && second_space != std::string::npos) {
                resp.status_code = std::stoi(line.substr(first_space + 1, second_space - first_space - 1));
            }
        }

        size_t body_pos = raw_response.find("\r\n\r\n");
        if (body_pos != std::string::npos) {
            resp.body = raw_response.substr(body_pos + 4);
        }

        return resp;
    }
};

#endif
