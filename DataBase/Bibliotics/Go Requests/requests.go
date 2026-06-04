package requests

import (
	"github.com/go-resty/resty/v2"
)

func SendOnlineRequest(apiKey string, url string) (*resty.Response, error) {
	client := resty.New()

	resp, err := client.R().
		SetHeader("Authorization", "Bearer "+apiKey).
		Get(url)

	return resp, err
}
