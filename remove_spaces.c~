#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <signal.h>
#include "main.h"


void remove_spaces(char *str)
{
int i, j;
for (i = 0, j = 0; str[i] != '\0'; i++)
{
if (str[i] != ' ')
{
str[j] = str[i];
j++;
}
}
str[j] = '\0';
}
