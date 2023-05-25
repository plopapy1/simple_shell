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
  * b_pre_buffer - buffer
  * @tok: char
  * Return: return b_pre
  */

char *b_pre_buffer(char *tok)
{
	char *b_space;

	b_space = (char *)malloc(strlen(tok) + 1);
		if (b_space == NULL)
	{
		printf("malloc failed\n");
		exit(1);
	}
		return (b_space);
}
