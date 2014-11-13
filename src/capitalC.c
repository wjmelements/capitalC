#include "capitalC.h"

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

 
#define DIE()\
    perror(__func__);\
    exit(errno)

#define DIEWITH(arg)\
    perror(arg);\
    exit(errno)


void Close(int fd) {
    int ret = close(fd);
    if (ret == -1) {
        DIE();
    }
}
void FClose(FILE* fp) {
    int ret = fclose(fp);
    if (ret == -1) {
        DIE();
    }
}
DIR* Fdopendir(int fd) {
    DIR* ret = fdopendir(fd);
    if (ret == NULL) {
        DIE();
    }
    return ret;
}
void Closedir(DIR* dp) {
    int ret = closedir(dp);
    if (ret == -1) {
        DIE();
    }
}
pid_t Fork(void) {
    pid_t ret = fork();
    if (ret == -1) {
        DIE();
    }
    return ret;
}
int Open(const char* path, int flags) {
    int ret = open(path, flags);
    if (ret == -1) {
        DIEWITH(path);
    }
    return ret;
}
FILE* Fopen(const char* path, const char* mode) {
    FILE* ret = fopen(path, mode);
    if (ret == NULL) {
        DIEWITH(path);
    }
    return ret;
}
void* Malloc(size_t size) {
    void* ret = malloc(size);
    if (ret == NULL) {
        DIE();
    }
    return ret;
}
void* Calloc(size_t nmemb, size_t size) {
    void* ret = calloc(nmemb, size);
    if (ret == NULL) {
        DIE();
    }
    return ret;
}
