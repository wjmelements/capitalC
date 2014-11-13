#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
void* Calloc(size_t nmemb, size_t size);
void Close(int fd);
void Closedir(DIR* dp);
void Fclose(FILE* fp);
FILE* Fopen(const char* path, const char* mode);
DIR* Fdopendir(int fd);
pid_t Fork(void);
void* Malloc(size_t size);
int Open(const char* path, int flags);
