package requests

import (
	"time"
	"github.com/go-resty/resty/v2"
)

func ConfigureClientSettings(client *resty.Client) {
	client.
		SetTimeout(15 * time.Second).
		SetRetryCount(3).
		SetRetryWaitTime(2 * time.Second).
		SetRetryMaxWaitTime(5 * time.Second).
		SetRedirectPolicy(resty.FlexibleRedirectPolicy(5))
}
