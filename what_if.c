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
 *what_if - function to run command if
 *@av: pointer to argument to check
 *Return: an int value
 */

int what_if(char *av[])
{
pid_t pid;
int execstat;

pid = fork();
if (pid == -1)
{
perror("child failed\n");
exit(-1);
}
if (pid == 0)
{
execstat = execve(av[0], av, NULL);
if (execstat == -1)
{
perror(NULL);
exit(-1);
}
}
return (0);
}
