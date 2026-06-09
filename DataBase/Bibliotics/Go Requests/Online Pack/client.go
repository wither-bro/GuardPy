package online

import (
	"encoding/json"
	"os"
	"requests"
)

type SharkClient struct {
	Name        string `json:"client_name"`
	Version     string `json:"version"`
	Environment string `json:"environment"`
	Settings    struct {
		Timeout         int  `json:"timeout_seconds"`
		RetryAttempts   int  `json:"retry_attempts"`
		EnableLogging   bool `json:"enable_logging"`
		SSLVerification bool `json:"ssl_verification"`
	} `json:"settings"`
	Endpoints struct {
		BaseURL  string `json:"base_url"`
		Auth     string `json:"auth"`
		Updates  string `json:"updates"`
		DataSync string `json:"data_sync"`
	} `json:"endpoints"`
}

func LoadSharkClient(configPath string) (*SharkClient, error) {
	file, err := os.ReadFile(configPath)
	if err != nil {
		return nil, err
	}

	var clientConfig SharkClient
	err = json.Unmarshal(file, &clientConfig)
	if err != nil {
		return nil, err
	}

	return &clientConfig, nil
}

func (sc *SharkClient) InitializeApiClient(apiKey string) *requests.ApiClient {
	client := requests.NewClient(apiKey)
	client.RestyClient.SetBaseURL(sc.Endpoints.BaseURL)
	requests.ConfigureClientSettings(client.RestyClient)
	
	return client
}
