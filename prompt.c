#include "header.h"
#include <sys/wait.h>
#define MAX_ELEMENT
/**
  *
  *
  *
  *
  */

int z, i, m, status;
char *string = NULL;
size_t n = 0;
ssize_t ret_char;
pid_t child_pid;
char *argv[MAX_ELEMENT];


void prompt(char **arguv, char **environ)
{
	for (z = 0; ; z++)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("cisfun$");
		}

		ret_char = getline(&string, &n, stdin);
		if (ret_char == 1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		i = 0
		while (string[i])
		{
			if (string[i] == '\n')
				string[i] = 0; i++
		}
		argv[0] = string;

		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE)
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
				printf("%s: no such file or directory \n", arguv[0])
			else
				wait(&status);
		}


	}

}
