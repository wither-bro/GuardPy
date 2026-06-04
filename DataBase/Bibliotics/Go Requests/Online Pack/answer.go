package online

import (
	"encoding/json"
	"github.com/go-resty/resty/v2"
)

type ServerAnswer struct {
	Status  string          `json:"status"`
	Code    int             `json:"code"`
	Message string          `json:"message"`
	Data    json.RawMessage `json:"data"`
}

func ParseServerAnswer(resp *resty.Response) (*ServerAnswer, error) {
	var answer ServerAnswer
	err := json.Unmarshal(resp.Body(), &answer)
	if err != nil {
		return nil, err
	}
	return &answer, nil
}
