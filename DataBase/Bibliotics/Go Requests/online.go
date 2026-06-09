package requests

import (
	"errors"
	"sync"
)

type OnlineManager struct {
	mu           sync.RWMutex
	activeNodes  map[string]bool
	nodeRegistry map[string]string
}

func NewOnlineManager() *OnlineManager {
	return &OnlineManager{
		activeNodes:  make(map[string]bool),
		nodeRegistry: make(map[string]string),
	}
}

func (om *OnlineManager) RegisterNode(nodeID string, nodeAddr string) {
	om.mu.Lock()
	defer om.mu.Unlock()

	om.activeNodes[nodeID] = true
	om.nodeRegistry[nodeID] = nodeAddr
}

func (om *OnlineManager) VerifyNode(nodeID string) error {
	om.mu.RLock()
	defer om.mu.RUnlock()

	if !om.activeNodes[nodeID] {
		return errors.New("NODE_OFFLINE_OR_UNAUTHORIZED")
	}
	return nil
}

func (om *OnlineManager) GetNodeAddress(nodeID string) (string, error) {
	om.mu.RLock()
	defer om.mu.RUnlock()

	addr, exists := om.nodeRegistry[nodeID]
	if !exists {
		return "", errors.New("NODE_NOT_FOUND")
	}
	return addr, nil
}

func (om *OnlineManager) DisconnectNode(nodeID string) {
	om.mu.Lock()
	defer om.mu.Unlock()

	delete(om.activeNodes, nodeID)
	delete(om.nodeRegistry, nodeID)
}
