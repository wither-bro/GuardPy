package id

import (
	"sync"
)

type EyeUniqueID struct {
	mu            sync.RWMutex
	trackingTable map[string]*UniqueID
}

func NewEyeUniqueID() *EyeUniqueID {
	return &EyeUniqueID{
		trackingTable: make(map[string]*UniqueID),
	}
}

func (e *EyeUniqueID) RegisterForTracking(uid *UniqueID) {
	e.mu.Lock()
	defer e.mu.Unlock()
	e.trackingTable[uid.Hash] = uid
}

func (e *EyeUniqueID) GetTrackedInfo(hash string) (*UniqueID, bool) {
	e.mu.RLock()
	defer e.mu.RUnlock()
	val, exists := e.trackingTable[hash]
	return val, exists
}

func (e *EyeUniqueID) CheckIntegrity(hash string) bool {
	e.mu.RLock()
	defer e.mu.RUnlock()
	_, exists := e.trackingTable[hash]
	return exists
}

func (e *EyeUniqueID) RemoveFromTracking(hash string) {
	e.mu.Lock()
	defer e.mu.Unlock()
	delete(e.trackingTable, hash)
}
