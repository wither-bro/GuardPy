package message

import (
	"encoding/json"
	"time"
)

type Message struct {
	ID        string    `json:"id"`
	Sender    string    `json:"sender"`
	Content   string    `json:"content"`
	Timestamp time.Time `json:"timestamp"`
}

func New(id string, sender string, content string) *Message {
	return &Message{
		ID:        id,
		Sender:    sender,
		Content:   content,
		Timestamp: time.Now(),
	}
}

func (m *Message) Serialize() ([]byte, error) {
	return json.Marshal(m)
}

func Deserialize(data []byte) (*Message, error) {
	var m Message
	err := json.Unmarshal(data, &m)
	return &m, err
}
