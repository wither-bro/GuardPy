package id

import (
	"crypto/rand"
	"encoding/hex"
	"fmt"
	"time"
)

type UserID struct {
	Value     string    `json:"value"`
	CreatedAt time.Time `json:"created_at"`
	Origin    string    `json:"origin"`
}

func GenerateNewID(origin string) (*UserID, error) {
	bytes := make([]byte, 16)
	if _, err := rand.Read(bytes); err != nil {
		return nil, err
	}

	idValue := hex.EncodeToString(bytes)
	
	return &UserID{
		Value:     fmt.Sprintf("GP-%s-%s", origin, idValue),
		CreatedAt: time.Now(),
		Origin:    origin,
	}, nil
}

func (u *UserID) String() string {
	return u.Value
}
