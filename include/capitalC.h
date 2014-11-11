#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
void Close(int fd);
void Fclose(FILE* fp);
DIR* Fdopendir(int fd);
pid_t Fork(void);
