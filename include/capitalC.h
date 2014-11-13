#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void* Calloc(size_t nmemb, size_t size);
void Close(int fd);
void Closedir(DIR* dp);
void Fclose(FILE* fp);
DIR* Fdopendir(int fd);
FILE* Fopen(const char* path, const char* mode);
pid_t Fork(void);
#define Free free
void Kill(pid_t pid, int sig);
void* Malloc(size_t size);
int Open(const char* path, int flags);
void Read(int fd, void* buf, size_t count);
void Snprintf(char* str, size_t size, const char* format, ...);
void Write(int fd, const void* buf, size_t count);
