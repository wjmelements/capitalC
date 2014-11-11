#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include "capitalC.h"
#include <fcntl.h>
int main() {
    pid_t pid = Fork();
    if (pid) {
        // parent
    } else {
        // child
        return -1;
    }
    int fd = Open("include/capitalC.h", O_NOATIME);
    int dfd = Open("include", O_DIRECTORY | O_NOATIME);
    DIR* dp = Fdopendir(dfd);
    Closedir(dp);
    Close(fd);
    return 0;
}
