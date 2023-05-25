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
 *main - the main function
 *Return: Nothing
 */

int main(void)
{
	pid_t pid;
	size_t n = 0;
	ssize_t getstat = 0;
	ssize_t execstat = 0;
	char *str = NULL;
	char *delim = {" \n"};
	char *token;
	char *av[] = {NULL};

	while (1)
	{
	printf("$ ");
	getstat = getline(&str, &n, stdin);
;
	if (getstat == -1)
	{
		perror("getfailed");
		return (-1);
	}
	token = strtok(str, delim);
	av[0] = token;
	av[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("child failed");
		return (-1);
	}
	if (pid == 0)
	{
	execstat = execve(av[0], av, NULL);
	if (execstat == -1)
	{
		perror("exec failed");
		return (-1);
	}
	}
	wait(NULL);
	free(token);
}
}
