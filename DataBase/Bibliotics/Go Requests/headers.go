package requests

import (
	"github.com/go-resty/resty/v2"
)

func SetDefaultHeaders(client *resty.Client) {
	client.
		SetHeader("Accept", "application/json").
		SetHeader("Content-Type", "application/json").
		SetHeader("User-Agent", "GuardPy-Client/1.0")
}

func SetAuthHeader(request *resty.Request, apiKey string) {
	request.SetHeader("Authorization", "Bearer "+apiKey)
}
