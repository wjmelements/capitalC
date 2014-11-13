#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include "capitalC.h"
#include <assert.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
int main() {
    pid_t pid = Fork();
    if (pid) {
        // parent
    } else {
        // child
        return -1;
    }
    if (pid = Fork()) {
        // parent
        Kill(pid, SIGKILL);
    } else {
        // child
        while (1);
    }
    char buf[16];
    char origin[16] = "abcdefg";
    Snprintf(buf, 16, origin);
    assert(strncmp(buf, origin, 16) == 0);
    int fd = Open("include/capitalC.h", O_NOATIME);
    int dfd = Open("include", O_DIRECTORY | O_NOATIME);
    DIR* dp = Fdopendir(dfd);
    Closedir(dp);
    Close(fd);
    const size_t buffer_size = 400000;
    char* buffer = Malloc(buffer_size);
    int rfd = Open("/dev/urandom", O_RDONLY);
    Read(rfd, buffer, buffer_size);
    Close(rfd);
    int dnfd = Open("/dev/null", O_WRONLY);
    Write(dnfd, buffer, buffer_size);
    Close(dnfd);
    Free(buffer);
    return 0;
}
