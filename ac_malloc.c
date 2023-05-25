#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>
#include "main.h"

char **ac_malloc(int ac, char *str)
{
	char **av;

	av = (char **)malloc(sizeof(char *) * ac);
	if (av == NULL)
	{
		free(str);
	    exit(EXIT_FAILURE);
	}
	return (av);
}
