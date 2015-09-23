#ifndef _syscall_h_
#define _syscall_h_

#include <errno.h>
#undef errno

extern "C" {

extern int errno;

}

#endif // _syscall_h_
