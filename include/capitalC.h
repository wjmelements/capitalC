#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
int Close(int fd);
int Fclose(FILE* fp);
DIR* Fdopendir(int fd);
pid_t Fork(void);
