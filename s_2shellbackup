#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "main.h"

int count_spaces(const char *input)
{
int count = 0;
while (*input != '\0' && input[0] == ' ')
{
input++;
if (*input == ' ')
{
if (*(input + 1) != '\n' && *(input - 1) != ' ' && *(input + 1) != ' ')
count++;
}
}

while (*input)
{
if (*input == ' ')
{
if (*(input + 1) != '\n' && *(input + 1) != '\0' && *(input + 1) != ' ')
count++;
}
input++;
}
count++;
return (count);
}



int main(void)
{
	pid_t pid;
	size_t n = 0;
	ssize_t getstat = 0;
	ssize_t execstat = 0;
	char *str = NULL;
	char *delim = {" \n"};
	char *token;
	char **av = NULL;
	int ac, count;


	while (1)
	{
	printf("$ ");
	getstat = getline(&str, &n, stdin);
	if (getstat == -1)
	{
		perror("getfailed");
		return (-1);
	}
	ac = count_spaces(str);
	av = (char **)malloc(sizeof(char *) * (ac + 1));

	token = strtok(str, delim);


	count = 0;
	while (count <= (ac - 1))
	{
		av[count] = token;
		printf("the value of av[%d] is %s\n", count, av[count]);
		count++;
		token = strtok(NULL, delim);
	}
	av[count] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("child failed\n");
		return (-1);
	}
	if (pid == 0)
	{
		printf("about to run exec\n");
	execstat = execve(av[0], av, NULL);
	printf("running exec\n");
	if (execstat == -1)
	{
		perror("exec failed\n");
		return (-1);
	}
	}
	wait(NULL);
	printf("back to parent\n");
}
	free(token);
	free(av);
}
