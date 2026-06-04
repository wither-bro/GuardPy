package id

import (
	"crypto/hmac"
	"crypto/sha256"
	"encoding/hex"
	"fmt"
)

type RootID struct {
	Value     string `json:"root_value"`
	Signature string `json:"signature"`
}

func GenerateRootID(baseID string, masterSecret string) *RootID {
	payload := fmt.Sprintf("ROOT-%s", baseID)
	
	h := hmac.New(sha256.New, []byte(masterSecret))
	h.Write([]byte(payload))
	signature := hex.EncodeToString(h.Sum(nil))

	return &RootID{
		Value:     payload,
		Signature: signature,
	}
}

func (r *RootID) Verify(masterSecret string) bool {
	h := hmac.New(sha256.New, []byte(masterSecret))
	h.Write([]byte(r.Value))
	expected := hex.EncodeToString(h.Sum(nil))
	
	return hmac.Equal([]byte(r.Signature), []byte(expected))
}
