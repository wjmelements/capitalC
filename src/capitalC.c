#include "capitalC.h"

#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdarg.h>
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
void Kill(pid_t pid, int sig) {
    int ret = kill(pid, sig);
    if (ret == -1) {
        int e = errno;
        char buf[16];
        switch (e) {
            case EINVAL:
                Snprintf(buf, sizeof(buf), "%i", sig);
                break;
            case EPERM:
            case ESRCH:
                Snprintf(buf, sizeof(buf), "%u", pid);
                break;
            default:
                DIE();
        }
        errno = e;
        DIEWITH(buf);
    }
}
void Snprintf(char* str, size_t size, const char* format, ...) {
    va_list arg;
    va_start(arg, format);
    int ret = vsnprintf(str, size, format, arg);
    if (ret < 0) {
        DIE();
    }
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
void Read(int fd, void* buf, size_t count) {
    while (1) {
        ssize_t ret = read(fd, buf, count);
        if (ret == -1) {
            switch (errno) {
                case EINTR:
                    // try again
                    break;
                default:
                    DIE();
            }
        } else if (ret < count) {
            count -= ret;
            buf += ret;
        } else {
            return;
        }
    }
}
void Write(int fd, const void* buf, size_t count) {
    while (1) {
        ssize_t ret = write(fd, buf, count);
        if (ret == -1) {
            switch (errno) {
                case EINTR:
                    // try again
                    break;
                default:
                    DIE();
            }
        } else if (ret < count) {
            count -= ret;
            buf += ret;
        } else {
            return;
        }
    }
}
