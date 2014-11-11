#include "capitalC.h"

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
inline void Close(int fd) {
    int ret = close(fd);
    if (ret == -1) {
        perror("Close");
        exit(errno);
    }
}
inline void FClose(FILE* fp) {
    int ret = fclose(fp);
    if (ret == -1) {
        perror("FClose");
        exit(errno);
    }
}
inline DIR* Fdopendir(int fd) {
    DIR* ret = fdopendir(fd);
    if (ret == NULL) {
        perror("Fdopendir");
        exit(errno);
    }
    return ret;
}
inline pid_t Fork(void) {
    pid_t ret = fork();
    if (ret == -1) {
        perror("Fork");
        exit(errno);
    }
    return ret;
}
