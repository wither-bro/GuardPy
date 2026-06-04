package online

import (
	"errors"
	"time"
)

type BanalManager struct {
	blacklist map[string]time.Time
}

func NewBanalManager() *BanalManager {
	return &BanalManager{
		blacklist: make(map[string]time.Time),
	}
}

func (bm *BanalManager) Ban(id string, duration time.Duration) {
	bm.blacklist[id] = time.Now().Add(duration)
}

func (bm *BanalManager) IsBanned(id string) (bool, error) {
	expiry, exists := bm.blacklist[id]
	if !exists {
		return false, nil
	}

	if time.Now().After(expiry) {
		delete(bm.blacklist, id)
		return false, nil
	}

	return true, errors.New("ACCESS_DENIED_ENTITY_IS_BANNED")
}

func (bm *BanalManager) Unban(id string) {
	delete(bm.blacklist, id)
}
