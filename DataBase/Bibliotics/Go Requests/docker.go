package requests

import (
	"fmt"
	"sync"
)

type DockerLibrary struct {
	mu            sync.RWMutex
	OnlineManager *OnlineManager
	IDRegistry    *IDRegistry
	RootRegistry  *RootRegistry
}

func NewDockerLibrary() *DockerLibrary {
	return &DockerLibrary{
		OnlineManager: NewOnlineManager(),
		IDRegistry:    NewIDRegistry(),
		RootRegistry:  NewRootRegistry(),
	}
}

func (dl *DockerLibrary) InitializeSession(userID string, nodeID string, rootLevel string) string {
	dl.mu.Lock()
	defer dl.mu.Unlock()

	dl.IDRegistry.Bind(userID, nodeID)
	dl.RootRegistry.AssignRoot(userID, rootLevel)
	
	return fmt.Sprintf("SESSION_INITIALIZED: User[%s] on Node[%s] with Level[%s]", userID, nodeID, rootLevel)
}

func (dl *DockerLibrary) GetStatus(userID string) string {
	dl.mu.RLock()
	defer dl.mu.RUnlock()

	node, _ := dl.IDRegistry.Resolve(userID)
	err := dl.RootRegistry.ValidateRootAccess(userID, "ADMIN")
	
	if err != nil {
		return fmt.Sprintf("USER: %s | NODE: %s | ACCESS: RESTRICTED", userID, node)
	}
	return fmt.Sprintf("USER: %s | NODE: %s | ACCESS: GRANTED", userID, node)
}
