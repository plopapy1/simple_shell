#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>
#include "main.h"

#define MAX_COMMAND 15

/**
 *tasktwo - launched task one
 *@arg: the argument passed
 *@env: the environemt variable
 *Return: Nothing;
 */
int tasktwo(char **arg, char **env)
{
	pid_t pid;
	size_t n = 0;
	int getstat = 0, status = 0, count, evc = 0;
	char *str = NULL, *ac[MAX_COMMAND], *delim = " \n";

while (1)
{
	if (isatty(STDIN_FILENO))
		printf("cisfun$ ");
	getstat = getline(&str, &n, stdin);
	if (getstat == -1)
	{
		free(str);
		exit(0);
	}

	str = r_newline(str);

	if (strcmp(str, "exit") == 0)
	{
		free(str);
		exit(0);
	}
if (strcmp(str, "env") == 0)
evc = envi(env);
if (evc == -1)
continue;
	if (str[0] == '\0')
		continue;
	if (non_interspace(str) == -1)
		continue;
	str = rm_leadingspace(str);
	if (strcmp(str, ".") != 0)
	{
	pre_fix(str);
		str = copydot(str);
	}
	ac[0] = strtok(str, delim);
	if (file_exist(ac[0]) == 0)
	{
	count = 0;
	while (ac[count] != NULL)
		ac[++count] = strtok(NULL, delim);
	pid = fork();
	if (pid == -1)
	{
		free(str);
		exit(0);
	}
	if (pid == 0)
	{
		if (execve(ac[0], ac, env) == -1)
		{
			free(str);
		printf("%s No such file or directory\n", arg[0]);
		exit(2);
		}
	}
	else
		wait(&status);
	}
	else
	{
			printf("files does not exist\n");

	continue;
	}
	continue;

}
free(str);
exit(0);
return (0);

}
