package requests

import (
	"errors"
	"sync"
)

type RootRegistry struct {
	mu          sync.RWMutex
	rootMasters map[string]string
}

func NewRootRegistry() *RootRegistry {
	return &RootRegistry{
		rootMasters: make(map[string]string),
	}
}

func (rr *RootRegistry) AssignRoot(userID string, rootLevel string) {
	rr.mu.Lock()
	defer rr.mu.Unlock()
	rr.rootMasters[userID] = rootLevel
}

func (rr *RootRegistry) ValidateRootAccess(userID string, requiredLevel string) error {
	rr.mu.RLock()
	defer rr.mu.RUnlock()

	level, exists := rr.rootMasters[userID]
	if !exists || level != requiredLevel {
		return errors.New("ROOT_ACCESS_LEVEL_INSUFFICIENT")
	}
	return nil
}

func (rr *RootRegistry) RevokeRoot(userID string) {
	rr.mu.Lock()
	defer rr.mu.Unlock()
	delete(rr.rootMasters, userID)
}
