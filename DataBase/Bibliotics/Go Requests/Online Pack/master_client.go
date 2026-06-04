package online

import (
	"errors"
	"sync"
)

type MasterClient struct {
	mu           sync.RWMutex
	clientVault  map[string]*SharkClient
	vataPassKeys map[string]string
}

func NewMasterClient() *MasterClient {
	return &MasterClient{
		clientVault:  make(map[string]*SharkClient),
		vataPassKeys: make(map[string]string),
	}
}

func (mc *MasterClient) RegisterAndIssuePass(id string, client *SharkClient, vataPass string) {
	mc.mu.Lock()
	defer mc.mu.Unlock()
	
	mc.clientVault[id] = client
	mc.vataPassKeys[id] = vataPass
}

func (mc *MasterClient) AccessSecureNode(id string, providedPass string) (*SharkClient, error) {
	mc.mu.RLock()
	defer mc.mu.RUnlock()

	storedPass, exists := mc.vataPassKeys[id]
	if !exists || storedPass != providedPass {
		return nil, errors.New("CRITICAL_SECURITY_BREACH: Invalid VataPass - Access Denied")
	}

	client, ok := mc.clientVault[id]
	if !ok {
		return nil, errors.New("CLIENT_NOT_FOUND")
	}

	return client, nil
}

func (mc *MasterClient) RevokeAccess(id string) {
	mc.mu.Lock()
	defer mc.mu.Unlock()
	
	delete(mc.clientVault, id)
	delete(mc.vataPassKeys, id)
}
