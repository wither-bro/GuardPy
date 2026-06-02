package gozig

/*
#cgo LDFLAGS: -L. -lgozig
extern void* allocate_message_buffer(long long count);
*/
import "C"
import "unsafe"

func InitMessageBuffer(count int) unsafe.Pointer {
    return unsafe.Pointer(C.allocate_message_buffer(C.longlong(count)))
}
