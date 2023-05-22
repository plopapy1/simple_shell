#include "header.h"
#include <sys/wait.h>
#include <stdlib.h>
#define MAX_ELEMENT 20
/**
  * main - Prompt of the program
  * @arguv: arguement vector
  * @env: environment
  *
  */

void input(char **arguv, char **environ)
{
	int i, z, m, status;
	char *string = NULL;
	size_t n = 0;
	ssize_t ret_char;
	pid_t child_pid;
	char *argv[MAX_ELEMENT];

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
		i = 0;
		while (string[i])
		{
			if (string[i] == '\n')
				string[i] = 0; 
			i++;
		}
		m = 0;
		argv[m] = strtok(string, " ");
		while (argv[m])
		{
			argv[++m] = strtok(NULL, " ");
		}

		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
		       printf("%s: no such file or directory \n", arguv[0]);
		}
		wait(&status);

	}

}
