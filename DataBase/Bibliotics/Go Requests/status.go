package requests

import (
	"fmt"
)

func GetSystemStatus(docker *DockerLibrary, userID string) string {
	return docker.GetStatus(userID)
}

func PrintStatus(status string) {
	fmt.Printf("CURRENT_STATUS: %s\n", status)
}
