#include <stdio.h>
#include "header.h"

/**
  * main - shell begins
  * @argc: arguement charater
  * @argv: arguement vector
  * @environ: the environment
  *
  * Return: return 0
  */

int main(int argc, char **argv, char **environ)
{
	if (argc == 1)
		input (argv, environ);
	return (0);
}
