package voice

/*
#cgo LDFLAGS: -L./Online/Chat/Voice_Chat -lvoice_processor
#include <stdlib.h>
extern void start_recording();
extern void stop_recording(int discard);
extern void lock_recording();
*/
import "C"

func StartVoiceRecording() {
	C.start_recording()
}

func LockVoiceRecording() {
	C.lock_recording()
}

func StopVoiceRecording(discard bool) {
	if discard {
		C.stop_recording(1)
	} else {
		C.stop_recording(0)
	}
}
