#include "capitalC.h"

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
void Close(int fd) {
    int ret = close(fd);
    if (ret == -1) {
        perror("Close");
        exit(errno);
    }
}
void FClose(FILE* fp) {
    int ret = fclose(fp);
    if (ret == -1) {
        perror("FClose");
        exit(errno);
    }
}
DIR* Fdopendir(int fd) {
    DIR* ret = fdopendir(fd);
    if (ret == NULL) {
        perror("Fdopendir");
        exit(errno);
    }
    return ret;
}
void Closedir(DIR* dp) {
    int ret = closedir(dp);
    if (ret == -1) {
        perror("closedir");
        exit(errno);
    }
}
pid_t Fork(void) {
    pid_t ret = fork();
    if (ret == -1) {
        perror("Fork");
        exit(errno);
    }
    return ret;
}
int Open(const char* path, int flags) {
    int ret = open(path, flags);
    if (ret == -1) {
        perror(path);
        exit(errno);
    }
    return ret;
}
FILE* Fopen(const char* path, const char* mode) {
    FILE* ret = fopen(path, mode);
    if (ret == NULL) {
        perror(path);
        exit(errno);
    }
    return ret;
}
