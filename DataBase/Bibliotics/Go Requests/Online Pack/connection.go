package online

import (
	"time"
	"net"
)

func TestConnection(host string) bool {
	timeout := 5 * time.Second
	conn, err := net.DialTimeout("tcp", host, timeout)
	if err != nil {
		return false
	}
	if conn != nil {
		conn.Close()
		return true
	}
	return false
}
