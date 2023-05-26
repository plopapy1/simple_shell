#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>
#include "main.h"

/**
  * copy - prefix function
  * @str: string input
  * Return: returning str
  */

char *copydot(char *str)
{
	char *destination = NULL;
	char *dotSlash;

dotSlash = strstr(str, "./");

if (dotSlash != NULL)
{
destination = (char *)malloc(strlen(dotSlash) + 1);
if (destination != NULL)
{
strcpy(destination, dotSlash);
return (destination);
}
}
return (str);
}

