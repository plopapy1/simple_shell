#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 *search_path - launched task one
 *@command: the argument passed
 *@env: the environemt variable
 *Return: Nothing;
 */

char *search_path(char *command, char **env)
{
char *path_env = NULL;
char *path = NULL;
char *dir = NULL;

int i;
for (i = 0; env[i] != NULL; i++)
{
if (strncmp(env[i], "PATH=", 5) == 0)
{
path_env = env[i];
break;
}
}

if (path_env != NULL)
{

path = strdup(path_env + 5);
dir = strtok(path, ":");


while (dir != NULL)
{
char *full_path = malloc(strlen(dir) + strlen(command) + 2);
sprintf(full_path, "%s/%s", dir, command);
if (access(full_path, X_OK) == 0)
{
free(path);
return (full_path);
}

free(full_path);
dir = strtok(NULL, ":");
}
}
free(path);
return (NULL);
}
