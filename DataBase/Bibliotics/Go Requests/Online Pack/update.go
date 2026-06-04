package online

import (
	"encoding/json"
	"time"
)

type UpdateInfo struct {
	Version     string    `json:"version"`
	UpdateURL   string    `json:"update_url"`
	Description string    `json:"description"`
	ReleaseDate time.Time `json:"release_date"`
	IsCritical  bool      `json:"is_critical"`
	PatchNotes  []string  `json:"patch_notes"`
}

func CheckForUpdates(om *OnlineManager, currentVersion string) (*UpdateInfo, error) {
	url := "https://api.guardpy.com/v1/update/check?current=" + currentVersion
	
	resp, err := om.Client.ExecuteGet(url)
	if err != nil {
		return nil, err
	}

	var updateData UpdateInfo
	err = json.Unmarshal(resp.Body(), &updateData)
	if err != nil {
		return nil, err
	}

	return &updateData, nil
}
