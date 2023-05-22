#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	size_t n, count, strcount = 0;
	ssize_t getstat = 0;
	ssize_t execstat = 0;
	char *str = NULL;
	char *delim = {" \n"};
	char *token;
	char **av = NULL;
	av = (char **)malloc(sizeof(char *) * 2);
	printf("before the while");
	while (1)
	{
	printf("$ ");
	getstat = getline(&str, &n, stdin);
	if (getstat == -1)
	{
		perror("getfailed");
		return (-1);
	}
	printf("before the token\n");

	token = strtok(str, delim);

printf("before the second while\n");
count = 0;
	while (count < 1)
	{
		av[count] = token;
		printf("the value of av[%ld] is %s\n", count, av[count]);
		count++;
	}
	av[count] = NULL;
	token = strtok(NULL, delim);
	if (token != NULL)
	{
	       strcount = strlen(token);
		printf("more than one argument passed\n");
		return (-1);
	}
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
