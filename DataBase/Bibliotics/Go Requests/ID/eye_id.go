package id

import (
	"errors"
	"sync"
)

type EyeID struct {
	mu          sync.RWMutex
	monitoredIDs map[string]bool
}

func NewEyeID() *EyeID {
	return &EyeID{
		monitoredIDs: make(map[string]bool),
	}
}

func (e *EyeID) Watch(id string) {
	e.mu.Lock()
	defer e.mu.Unlock()
	e.monitoredIDs[id] = true
}

func (e *EyeID) IsUnderObservation(id string) bool {
	e.mu.RLock()
	defer e.mu.RUnlock()
	return e.monitoredIDs[id]
}

func (e *EyeID) ReportAnomaly(id string) error {
	e.mu.RLock()
	defer e.mu.RUnlock()
	
	if !e.monitoredIDs[id] {
		return errors.New("ID_NOT_UNDER_SURVEILLANCE")
	}
	return nil
}

func (e *EyeID) Unwatch(id string) {
	e.mu.Lock()
	defer e.mu.Unlock()
	delete(e.monitoredIDs, id)
}
