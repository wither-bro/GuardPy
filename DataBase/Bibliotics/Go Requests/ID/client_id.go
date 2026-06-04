package id

import (
	"fmt"
	"time"
)

type ClientAccount struct {
	ClientID    string    `json:"client_id"`
	AccountHash string    `json:"account_hash"`
	CreatedAt   time.Time `json:"created_at"`
	IsActive    bool      `json:"is_active"`
}

func RegisterClient(prefix string) *ClientAccount {
	now := time.Now()
	id := fmt.Sprintf("CLIENT-%s-%x", prefix, now.Unix())
	hash := fmt.Sprintf("%s:%d:SECURE_BIND", id, now.Unix())

	return &ClientAccount{
		ClientID:    id,
		AccountHash: hash,
		CreatedAt:   now,
		IsActive:    true,
	}
}

func (c *ClientAccount) Deactivate() {
	c.IsActive = false
}
