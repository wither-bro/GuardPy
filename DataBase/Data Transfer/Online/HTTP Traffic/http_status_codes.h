#ifndef HTTP_STATUS_CODES_H
#define HTTP_STATUS_CODES_H

enum class HttpStatus {
    OK = 200,
    CREATED = 201,
    BAD_REQUEST = 400,
    UNAUTHORIZED = 401,
    FORBIDDEN = 403,
    NOT_FOUND = 404,
    INTERNAL_SERVER_ERROR = 500
};

#endif
