package id

import (
	"sync"
)

type EyeRootID struct {
	mu            sync.RWMutex
	surveillance  map[string]*RootID
}

func NewEyeRootID() *EyeRootID {
	return &EyeRootID{
		surveillance: make(map[string]*RootID),
	}
}

func (e *EyeRootID) TrackRoot(rootID *RootID) {
	e.mu.Lock()
	defer e.mu.Unlock()
	e.surveillance[rootID.Value] = rootID
}

func (e *EyeRootID) IsRootCompromised(rootID *RootID, masterSecret string) bool {
	e.mu.RLock()
	defer e.mu.RUnlock()
	
	record, exists := e.surveillance[rootID.Value]
	if !exists {
		return true
	}
	
	return !record.Verify(masterSecret)
}

func (e *EyeRootID) StopTracking(rootValue string) {
	e.mu.Lock()
	defer e.mu.Unlock()
	delete(e.surveillance, rootValue)
}
