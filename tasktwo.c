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
 *taskone - launched task one
 *@arg: the argument passed
 *@env: the environemt variable
 *Return: Nothing;
 */
void tasktwo(char **arg, char **env)
{
	pid_t pid;
	size_t n;
	int getstat, status, count;
	char *str = NULL, *ac[MAX_COMMAND], *delim = " \n";

while (1)
{
	if (isatty(STDIN_FILENO))
		printf("cisfun$ ");
	getstat = getline(&str, &n, stdin);
	if (getstat == -1)/* if getline failes*/
	{
		free(str);
		exit(0);
	}
	str = r_newline(str); /*remove newlineracter*/
	if (str[0] == '\0')
		continue;
	ac[0] = strtok(str, delim);
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
		exit(0);
	}
	else
	wait(&status);
}
exit(0);
}
