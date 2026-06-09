package requests

import (
	"fmt"
)

func ExecuteRoutine(docker *DockerLibrary, door *Door, userID string) {
	if door.IsOpen() {
		fmt.Printf("ROUTINE_STARTED: User %s has access.\n", userID)
	} else {
		fmt.Printf("ROUTINE_BLOCKED: Door is locked for User %s.\n", userID)
	}
}
