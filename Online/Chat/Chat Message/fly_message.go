package chat

/*
#cgo LDFLAGS: -L./Online/Messages/Message -lcache_message
#include <stdlib.h>
extern void* handle_incoming_message(char* sender, char* text, long long len);
*/
import "C"
import (
	"unsafe"
)

func SendMessage(sender [32]byte, content string) {
	if len(content) > 20000000 {
		return
	}

	cSender := C.CBytes(sender[:])
	defer C.free(cSender)

	cText := C.CString(content)
	defer C.free(unsafe.Pointer(cText))

	C.handle_incoming_message((*C.char)(cSender), cText, C.longlong(len(content)))
}
