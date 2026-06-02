package store

import (
	"sync"
	"GuardPy/Online/Messages/Message"
)

type Store struct {
	mu       sync.RWMutex
	messages map[string]*message.Message
}

func New() *Store {
	return &Store{
		messages: make(map[string]*message.Message),
	}
}

func (s *Store) Save(msg *message.Message) {
	s.mu.Lock()
	defer s.mu.Unlock()
	s.messages[msg.ID] = msg
}

func (s *Store) Get(id string) *message.Message {
	s.mu.RLock()
	defer s.mu.RUnlock()
	return s.messages[id]
}
