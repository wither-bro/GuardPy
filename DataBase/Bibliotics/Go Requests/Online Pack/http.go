package online

import (
	"bytes"
	"net/http"
	"time"
)

type HttpService struct {
	Timeout time.Duration
}

func NewHttpService(seconds int) *HttpService {
	return &HttpService{
		Timeout: time.Duration(seconds) * time.Second,
	}
}

func (s *HttpService) Ping(url string) (int, error) {
	client := &http.Client{Timeout: s.Timeout}
	resp, err := client.Get(url)
	if err != nil {
		return 0, err
	}
	defer resp.Body.Close()
	return resp.StatusCode, nil
}

func (s *HttpService) PostRaw(url string, data []byte) (*http.Response, error) {
	client := &http.Client{Timeout: s.Timeout}
	return client.Post(url, "application/json", bytes.NewBuffer(data))
}
