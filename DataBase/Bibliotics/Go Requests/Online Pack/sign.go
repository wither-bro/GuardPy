package online

import (
	"crypto/hmac"
	"crypto/sha256"
	"encoding/hex"
)

func GenerateSignature(data string, secretKey string) string {
	h := hmac.New(sha256.New, []byte(secretKey))
	h.Write([]byte(data))
	return hex.EncodeToString(h.Sum(nil))
}

func VerifySignature(data string, signature string, secretKey string) bool {
	expectedSignature := GenerateSignature(data, secretKey)
	return hmac.Equal([]byte(signature), []byte(expectedSignature))
}
