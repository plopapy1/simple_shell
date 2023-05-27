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
 *environ - print environment variable
 *@env: the environment variable
 *Return: zero
 */
int envi(char **en)
{
	int i;

	for (i = 0; en[i] != NULL; i++)
	{
		printf("%s\n", en[i]);
	}
	return (-1);
}
