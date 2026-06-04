package requests

import (
	"errors"
	"github.com/go-resty/resty/v2"
)

var (
	ErrUnauthorized = errors.New("401: Unauthorized - Invalid API Key")
	ErrForbidden    = errors.New("403: Forbidden - Access Denied")
	ErrNotFound     = errors.New("404: Not Found")
	ErrServerError  = errors.New("500: Internal Server Error")
)

func CheckResponseError(resp *resty.Response) error {
	if resp.IsSuccess() {
		return nil
	}

	switch resp.StatusCode() {
	case 401:
		return ErrUnauthorized
	case 403:
		return ErrForbidden
	case 404:
		return ErrNotFound
	case 500:
		return ErrServerError
	default:
		return errors.New("Unknown Error occurred")
	}
}
