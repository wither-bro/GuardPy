package online

import (
	"requests"
)

type OnlineManager struct {
	Client *requests.ApiClient
}

func NewOnlineManager(apiKey string) *OnlineManager {
	client := requests.NewClient(apiKey)
	requests.ConfigureClientSettings(client.RestyClient)
	
	return &OnlineManager{
		Client: client,
	}
}

func (om *OnlineManager) CheckConnection(url string) bool {
	resp, err := om.Client.ExecuteGet(url)
	if err != nil {
		return false
	}
	return resp.IsSuccess()
}
