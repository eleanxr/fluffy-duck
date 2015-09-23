#include <syscall.h>

extern "C" {
    /// @brief Minimal implementation from newlib documentation.
    int _getpid() {
        return 1;
    }
}
