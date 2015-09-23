#include <syscall.h>

extern "C" {
    /// @brief Minimal kill implementation from newlib documentation.
    int _kill(int pid, int sig) {
        errno = EINVAL;
        return -1;
    }
}
