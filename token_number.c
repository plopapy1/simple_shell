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
 *token number - find number of arguments
 *@input: number of arguments passed
 *Return: int value
 */
int token_number(char *input)
{
int count = 0;
char *delim = " \n", *token = NULL;

token = strtok(input, delim);
while (token != NULL)
{
	count++;
	token = strtok(NULL, delim);
}
return (count);
}
