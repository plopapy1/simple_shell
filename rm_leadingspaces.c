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
 *rm_leadingspace - remove the spaces that are at the beginning of a string
 *@strr: str to remove space
 *Return: Nothing;
 */

char *rm_leadingspace(char *strr)
{
	int leadingSpaces;
	int len, i;
if (strr == NULL)
{
	return (NULL);
}

len = strlen(strr);
leadingSpaces = 0;


while (leadingSpaces < len && strr[leadingSpaces] == ' ')
{
leadingSpaces++;
}


for (i = 0; i < len - leadingSpaces; i++)
{
strr[i] = strr[i + leadingSpaces];
}


strr[len - leadingSpaces] = '\0';

return (strr);
}
