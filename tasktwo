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
void tasktwo(char **arg, char **env)
{
	pid_t pid;
	size_t n;
	int getstat, status, count, evc;
	char *str = NULL, *ac[MAX_COMMAND], *delim = " \n";
signal(SIGINT, ter_minate);
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
		exit(0);
if (strcmp(str, "env") == 0)
evc = envi(env);
if (evc == -1)
continue;
	if (str[0] == '\0')
		continue;
	if (non_interspace(str) == -1)
		continue;
	str = rm_leadingspace(str);

	pre_fix(str);
		str = copydot(str);

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
		printf("%s No such file or directory\n", arg[0]);
	}
	else
		wait(&status);
	}
	else
			printf("files does not exist\n");

	continue;

}
free(str);
exit(0);
}
