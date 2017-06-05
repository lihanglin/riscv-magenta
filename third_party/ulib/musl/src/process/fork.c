#include "libc.h"
#include "pthread_impl.h"
#include <string.h>
#include <unistd.h>

static void dummy(int x) {}

weak_alias(dummy, __fork_handler);

pid_t fork(void) {
    pid_t ret;
    __fork_handler(-1);
    // TODO(kulakowski) Some level of fork emulation.
    ret = ENOSYS;

    if (!ret) {
        // TODO(kulakowski): NB: fork assumes that the calling thread
        // is a pthread, and that the created thread in the new
        // process will therefore also be a pthread.
        pthread_t self = __pthread_self();
        if (self == NULL)
            __builtin_trap();
    }
    __fork_handler(!ret);
    return ret;
}
