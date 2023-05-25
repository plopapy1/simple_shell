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
int count_spaces(char *input)
{
int count = 0;
char *delim = " \n\t\r", *token;
token = strtok(input, delim);
if (token == NULL)
{
	return (0);
}
while (token)
{
	token = strtok(NULL, delim);
	count++;
}
return (count);
}

/**
 *av_buffer - function to create buffer for av
 *@ac: pointer one
 *@str: pointer two
 *Return: av
 */
char **av_buffer(int ac, char *strr)
{
char **av;
	(void)strr;
av = (char **)malloc(sizeof(char *) * (ac + 1));
if (av == NULL)
{
exit(EXIT_FAILURE);
}
return (av);
}
