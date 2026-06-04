package requests

import (
	"github.com/go-resty/resty/v2"
)

type ApiClient struct {
	RestyClient *resty.Client
	ApiKey      string
}

func NewClient(apiKey string) *ApiClient {
	client := resty.New()
	SetDefaultHeaders(client)
	
	return &ApiClient{
		RestyClient: client,
		ApiKey:      apiKey,
	}
}

func (c *ApiClient) ExecuteGet(url string) (*resty.Response, error) {
	req := c.RestyClient.R()
	SetAuthHeader(req, c.ApiKey)
	
	resp, err := req.Get(url)
	if err != nil {
		return nil, err
	}
	
	return resp, CheckResponseError(resp)
}
