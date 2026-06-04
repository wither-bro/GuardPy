package online

import (
	"requests"
)

func CreateImportClient(apiKey string) *requests.ApiClient {
	client := requests.NewClient(apiKey)
	requests.ConfigureClientSettings(client.RestyClient)
	return client
}
