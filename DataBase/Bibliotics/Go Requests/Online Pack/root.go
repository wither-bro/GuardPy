package online

import (
	"errors"
	"sync"
)

type RootManager struct {
	mu          sync.RWMutex
	rootGranted map[string]bool
}

func NewRootManager() *RootManager {
	return &RootManager{
		rootGranted: make(map[string]bool),
	}
}

func (rm *RootManager) GrantRootAccess(id string) {
	rm.mu.Lock()
	defer rm.mu.Unlock()
	rm.rootGranted[id] = true
}

func (rm *RootManager) VerifyRoot(id string) error {
	rm.mu.RLock()
	defer rm.mu.RUnlock()

	if !rm.rootGranted[id] {
		return errors.New("ROOT_ACCESS_REQUIRED")
	}
	return nil
}

func (rm *RootManager) RevokeRoot(id string) {
	rm.mu.Lock()
	defer rm.mu.Unlock()
	delete(rm.rootGranted, id)
}
