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
 *@argc: number of argument
 *@argv: the arguments
 *@envp: the environment variable
 *Return: nothing
 */
int main(int argc, char **argv, char **envp)
{

	if (argc >= 0)
	{
		tasktwo(argv, envp);
	}
		return (0);
}
