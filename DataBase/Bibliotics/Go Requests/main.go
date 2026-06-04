package requests

import (
	"fmt"
)

func RunSystemCheck(docker *DockerLibrary, door *Door, userID string, nodeID string, level string) {
	status := docker.InitializeSession(userID, nodeID, level)
	fmt.Println(status)

	err := door.Unlock(userID, docker.RootRegistry, level)
	if err != nil {
		fmt.Println("Error:", err)
	} else {
		fmt.Println("Door status: Open =", door.IsOpen())
	}

	fmt.Println("System check:", docker.GetStatus(userID))
}
