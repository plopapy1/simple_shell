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
 *ter_minate - exit in next line
 *@sig: the signal
 *Return: Nothing
 */

void ter_minate(int sig)
{
	(void)sig;
	printf("\n");
	exit(EXIT_SUCCESS);
}

/**
 *count_spaces - find number of arguments
 *@input: number of arguments passed
 *Return: int value
 */
int count_spaces(const char *input)
{
int count = 0;
while (*input != '\0' && input[0] == ' ')
{
input++;
if (*input == ' ')
{
if (*(input + 1) != '\n' && *(input - 1) != ' ' && *(input + 1) != ' ')
count++;
}
}

while (*input)
{
if (*input == ' ')
{
if (*(input + 1) != '\n' && *(input + 1) != '\0' && *(input + 1) != ' ')
count++;
}
input++;
}
count++;
return (count);
}


/**
 *av_buffer - function to create buffer for av
 *@ac: pointer one
 *@str: pointer two
 *Return: av
 */
char **av_buffer(int ac, char *str)
{
char **av = (char **)malloc(sizeof(char *) * (ac + 1));
if (av == NULL)
{
free(str);
printf("malloc failed\n");
exit(1);
}
return (av);
}
