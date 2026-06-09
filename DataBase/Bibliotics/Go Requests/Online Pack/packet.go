package online

import (
	"encoding/json"
	"errors"
	"time"
)

type DataPacket struct {
	ID        string          `json:"id"`
	Payload   json.RawMessage `json:"payload"`
	Timestamp time.Time       `json:"timestamp"`
	Signature string          `json:"signature"`
	Version   string          `json:"version"`
}

func CreatePacket(id string, data interface{}, secretKey string) (*DataPacket, error) {
	payload, err := json.Marshal(data)
	if err != nil {
		return nil, err
	}

	packet := &DataPacket{
		ID:        id,
		Payload:   payload,
		Timestamp: time.Now(),
		Version:   "1.0.0",
	}

	packet.Signature = GenerateSignature(string(payload), secretKey)
	return packet, nil
}

func (p *DataPacket) Validate(secretKey string) error {
	if !VerifySignature(string(p.Payload), p.Signature, secretKey) {
		return errors.New("INTEGRITY_CHECK_FAILED")
	}
	return nil
}

func (p *DataPacket) UnmarshalPayload(v interface{}) error {
	return json.Unmarshal(p.Payload, v)
}
