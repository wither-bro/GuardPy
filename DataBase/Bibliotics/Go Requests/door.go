package requests

import (
	"errors"
	"sync"
)

type Door struct {
	mu           sync.RWMutex
	locked       bool
	accessPolicy map[string]string
}

func NewDoor() *Door {
	return &Door{
		locked:       true,
		accessPolicy: make(map[string]string),
	}
}

func (d *Door) Unlock(userID string, registry *RootRegistry, level string) error {
	d.mu.Lock()
	defer d.mu.Unlock()

	if err := registry.ValidateRootAccess(userID, level); err != nil {
		return errors.New("DOOR_ACCESS_DENIED_INVALID_CREDENTIALS")
	}

	d.locked = false
	return nil
}

func (d *Door) Lock() {
	d.mu.Lock()
	defer d.mu.Unlock()
	d.locked = true
}

func (d *Door) IsOpen() bool {
	d.mu.RLock()
	defer d.mu.RUnlock()
	return !d.locked
}
