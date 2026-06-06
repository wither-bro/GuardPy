package main

import (
	"fmt"
	"os"
	"os/exec"
	"runtime"
)

func main() {
	if err := runClient(); err != nil {
		fmt.Printf("Error: %v\n", err)
		os.Exit(1)
	}
}

func runClient() error {
	var binaryName string
	switch runtime.GOOS {
	case "windows":
		binaryName = "./GuardPy.exe"
	case "darwin":
		binaryName = "./GuardPy_mac"
	default:
		binaryName = "./GuardPy_linux"
	}

	cmd := exec.Command(binaryName)
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	cmd.Stdin = os.Stdin

	go manageOnlineServices()

	return cmd.Run()
}

func manageOnlineServices() {
	fmt.Println("Online services started")
}
