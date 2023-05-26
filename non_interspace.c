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
 *non_interspace - launched task one
 *@string: the string to check
 *Return: int value
 */

int non_interspace(char *string)
{
	char *duplicate;

	duplicate = strdup(string);

	remove_spaces(duplicate);

	if (duplicate[0] == '\0')
	{
		free(duplicate);
		return (-1);
	}
	free(duplicate);
	return (0);
}
