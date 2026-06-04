package online

import (
	"sync"
)

type ClientManager struct {
	mu      sync.RWMutex
	clients map[string]*SharkClient
}

func NewClientManager() *ClientManager {
	return &ClientManager{
		clients: make(map[string]*SharkClient),
	}
}

func (cm *ClientManager) RegisterClient(id string, client *SharkClient) {
	cm.mu.Lock()
	defer cm.mu.Unlock()
	cm.clients[id] = client
}

func (cm *ClientManager) GetClient(id string) (*SharkClient, bool) {
	cm.mu.RLock()
	defer cm.mu.RUnlock()
	client, exists := cm.clients[id]
	return client, exists
}

func (cm *ClientManager) RemoveClient(id string) {
	cm.mu.Lock()
	defer cm.mu.Unlock()
	delete(cm.clients, id)
}

func (cm *ClientManager) Count() int {
	cm.mu.RLock()
	defer cm.mu.RUnlock()
	return len(cm.clients)
}
