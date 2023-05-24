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
  * file_in_path_exist - path of file exist
  * @filename: pointer to file name
  * Return: returning either 0 or 1
  */

int file_in_path_exist(const char *filename)
{
	char path[256];
	char *direct[] = { "/bin/" };
const char binSubstring[] = "/bin/";
char *newFilename;
if (strncmp(filename, binSubstring, sizeof(binSubstring) - 1) == 0)
{
const char *binPos = strstr(filename, binSubstring);
if (binPos != NULL)
{
size_t binLength = strlen(binSubstring);
size_t newFilenameLength = strlen(filename) - binLength;
newFilename = (char *)malloc(newFilenameLength + 1);
strncpy(newFilename, filename, binPos - filename);
strcpy(newFilename + (binPos - filename), binPos + binLength);
strcpy(path, direct[0]);
strcat(path, newFilename);
}
if (access(path, F_OK) != -1)
{
free(newFilename);
return (0);
}
free(newFilename);
return (-1);