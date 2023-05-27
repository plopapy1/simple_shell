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
 *ter_minate - exit in next line
 *@sig: the signal
 *Return: Nothing
 */

int ter_minate(int sig)
{
	(void)sig;
	return (0);

}
