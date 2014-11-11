#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
void Close(int fd);
void Closedir(DIR* dp);
void Fclose(FILE* fp);
FILE* Fopen(const char* path, const char* mode);
DIR* Fdopendir(int fd);
pid_t Fork(void);
int Open(const char* path, int flags);
