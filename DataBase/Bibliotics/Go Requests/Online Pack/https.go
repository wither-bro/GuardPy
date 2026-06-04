package online

import (
	"crypto/tls"
	"net/http"
	"time"
)

func CreateSecureTransport() *http.Transport {
	return &http.Transport{
		TLSClientConfig: &tls.Config{
			MinVersion:               tls.VersionTLS13,
			PreferServerCipherSuites: true,
		},
		TLSHandshakeTimeout: 10 * time.Second,
	}
}

func GetSecureHttpClient(timeoutSeconds int) *http.Client {
	return &http.Client{
		Timeout:   time.Duration(timeoutSeconds) * time.Second,
		Transport: CreateSecureTransport(),
	}
}

func VerifySSL(url string) bool {
	client := GetSecureHttpClient(5)
	resp, err := client.Get(url)
	if err != nil {
		return false
	}
	defer resp.Body.Close()
	return resp.TLS != nil && len(resp.TLS.PeerCertificates) > 0
}
