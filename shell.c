#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>
#include "main.h"

/*
 *main - the mainfunction
 *@argc: the number of arguments
 *@argv: the arguments
 *Return: the result of the addition
 */

int substract(int num1, int num2)
{
	int sum;

	sum = (num1 - num2);
	return (sum);
}
