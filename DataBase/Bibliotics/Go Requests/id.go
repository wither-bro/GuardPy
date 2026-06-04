package requests

import (
	"sync"
)

type IDRegistry struct {
	mu        sync.RWMutex
	idMapping map[string]string
}

func NewIDRegistry() *IDRegistry {
	return &IDRegistry{
		idMapping: make(map[string]string),
	}
}

func (ir *IDRegistry) Bind(userID string, nodeID string) {
	ir.mu.Lock()
	defer ir.mu.Unlock()
	ir.idMapping[userID] = nodeID
}

func (ir *IDRegistry) Resolve(userID string) (string, bool) {
	ir.mu.RLock()
	defer ir.mu.RUnlock()
	nodeID, exists := ir.idMapping[userID]
	return nodeID, exists
}

func (ir *IDRegistry) Unbind(userID string) {
	ir.mu.Lock()
	defer ir.mu.Unlock()
	delete(ir.idMapping, userID)
}
