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
 * main - to subtract two numbers
 *Return: nothing
 */
int main(int argc, char *argv[])
{
	pid_t pid;
	size_t n;
	int getstat;
	char *str, **av = NULL;

while (1)
{
	if (isatty(STDIN_FILENO))
		printf("cisfun$ ");
	getstat = getline(&str, &n, stdin);
	if (getstat == -1)/* if getline failes*/
	{
		free(str);
		exit(EXIT_FAILURE);
	}
	str = r_newline(str); /*remove newline character*/
	av = ac_malloc(argc, str);
	av[0] = str;
	av[1] = NULL;
	if (argc < 2)
	{
	pid = fork();
	if (pid == -1)
	{
		free(str);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(av[0], av, NULL) == -1)
		printf("%s No such file or directory\n", argv[0]);
	}
	wait(NULL);
	}
	else
	{
		free(av);
		continue;
	}
	free(av);
}
}
