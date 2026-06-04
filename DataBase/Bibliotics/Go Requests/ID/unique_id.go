package id

import (
	"crypto/sha256"
	"encoding/hex"
	"fmt"
	"time"
)

type UniqueID struct {
	Hash      string    `json:"hash"`
	BaseID    string    `json:"base_id"`
	Timestamp int64     `json:"timestamp"`
}

func GenerateUnique(baseID string) *UniqueID {
	timestamp := time.Now().UnixNano()
	input := fmt.Sprintf("%s-%d", baseID, timestamp)
	
	hash := sha256.Sum256([]byte(input))
	
	return &UniqueID{
		Hash:      hex.EncodeToString(hash[:]),
		BaseID:    baseID,
		Timestamp: timestamp,
	}
}

func (u *UniqueID) GetShort() string {
	return u.Hash[:16]
}
