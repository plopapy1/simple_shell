#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>
#include "main.h"

int file_exist(const char *filename)
{
char path[256];
char *direct[] = {"/bin/"};
strcpy(path, direct[0]);
strcat(path, filename);
if (access(path, F_OK) != -1)
{
return (0);
}
return (-1);
}

char *pre_fix(char *str)
{
const char dir[] = "/bin/";


if (strncmp(str, dir, sizeof(dir) - 1) != 0)
{

size_t oLen = strlen(str);
size_t nLen = sizeof(dir) - 1 + oLen + 1;
char *newStr = (char *)malloc(nLen);

strcpy(newStr, dir);

strcat(newStr, str);

strcpy(str, newStr);

free(newStr);
}
return (str);
}


void ter_minate(int sig)
{
	(void)sig;
	printf("\n");
	exit(EXIT_SUCCESS);
}

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
	ssize_t getstat, execstat = 0;
	char *chk_file;
	char *str = NULL, *delim = " \n", *token, *pre_pre, *b_pre, **av = NULL;
	int ac, count, chk_int;
	signal(SIGINT, ter_minate);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

	getstat = getline(&str, &n, stdin);
	if (getstat == -1)
	{
		break;
	}
	ac = count_spaces(str);
	av = (char **)malloc(sizeof(char *) * (ac + 1));
	if (av == NULL)
	{
		printf("malloc failed\n");
		exit(0);
	}
	token = strtok(str, delim);
		if (strcmp("exit", token) == 0)
		break;
	b_pre = (char *)malloc(strlen(token) + 1);
	strcpy(b_pre, token);
	chk_file = b_pre;
	chk_int = file_exist(chk_file);
	pre_pre = pre_fix(b_pre);
	count = 0;
	av[0] = pre_pre;
	while (count < (ac - 1))
	{
		count++;
		token = strtok(NULL, delim);
		av[count] = token;

	}
	count++;
	av[count] = NULL;
	if (chk_int == 0)
	{
		printf("ran fork\n");
	pid = fork();
	if (pid == -1)
	{
		perror("child failed\n");
		return (-1);
	}
	if (pid == 0)
	{
	execstat = execve(av[0], av, NULL);
	if (execstat == -1)
	{
		perror(NULL);
		return (-1);
	}
	}
	}
	else
		printf("file does not exist\n");
	wait(NULL);
	free(av);
}
	free(str);
	return (0);
}