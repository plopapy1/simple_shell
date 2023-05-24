#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>
#include "main.h"

char *pre_fix(char *str)
{
const char dir[] = "/bin/";
if (strncmp(str, dir, sizeof(dir) - 1) != 0)
{

size_t oLen = strlen(str);
size_t nLen = sizeof(dir) - 1 + oLen + 1;
char *newStr = (char *)malloc(nLen);
	if (newStr == NULL)
	{
		printf("malloc failed\n");
		exit(1);
	}

strcpy(newStr, dir);

strcat(newStr, str);

strcpy(str, newStr);

free(newStr);
}
return (str);
}
