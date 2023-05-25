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
	char **av = NULL;

	av = (char **)malloc(sizeof(char *) * (ac + 1));
	printf("ac = %d", ac);
	printf("size of av[0] is %ld\n", sizeof(av[0]));
	printf("size of av[1] is %ld\n", sizeof(av[1]));
	printf("size of av[2] is %ld\n", sizeof(av[2]));

	if (av == NULL)
	{
		printf("it is null\n");
		free(str);
	    exit(EXIT_FAILURE);
	}
	return (av);
}
