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
  * file_exist - file exit check
  * @filename: file name
  * Return: returnung o or 1
  */

int file_exist(const char *filename)
{
if (access(filename, F_OK) != -1)
{
return (0);
}
return (-1);
}
