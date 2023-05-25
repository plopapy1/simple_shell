#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>
#include "main.h"

char *r_newline(char *str)
{
	int nullcount = 0;

	while (str[nullcount] != '\0')
	{
		if (str[nullcount] == '\n')
		{
			str[nullcount] = '\0';
		}
		nullcount++;
	}
	return (str);
}
