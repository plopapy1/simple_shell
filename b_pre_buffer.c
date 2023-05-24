#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>
#include "main.h"


char *b_pre_buffer(char *tok)
{
	char *b_pre = (char *)malloc(strlen(tok) + 1);
		if (b_pre == NULL)
	{
		printf("malloc failed\n");
		exit(1);
	}
		return (b_pre);
}
