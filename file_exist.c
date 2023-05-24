#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>
#include "main.h"

int file_exist(const char *filename)
{
char path[256];
char *direct[] = {"/bin/"};
strcpy(path, direct[0]);
strcat(path, filename);
if (access(path, F_OK) != -1)
{
return (0);
}
return (-1);
}
