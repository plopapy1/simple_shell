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
 *free_end - function to free malloc space
 *@buf: pointer one
 *@buff: pointer two
 *@bufff: pointer three
 *Return: Nothing
 */
void free_end(char *buf, char *buff, char *bufff)
{
	free(buf);
	free(buff);
	free(bufff);
}

/**
 *main - the main function
 *@argc: number of arguments
 *@argv: pointer to array of arguments
 *Return: zero
 */
int main(int argc, char *argv[])
{
	size_t n = 0;
	ssize_t getstat;
	char *chk_file, *o_cmd, *str_dup;
char *str = NULL, *delim = " \n", *token, *pre_pre, *b_pre, **av = NULL;
	int ac, count, chk_int, echo_chk;

	signal(SIGINT, ter_minate);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("cisfun$ ");
	getstat = getline(&str, &n, stdin);
	if (getstat == -1)
		break;
	if (str[0] == '\n')
		continue;
	str_dup = strdup(str);
	ac = count_spaces(str);
	av = av_buffer(ac, str);
	token = strtok(str_dup, delim);
		if (strcmp("exit", token) == 0)
		break;
	b_pre = b_pre_buffer(token);
	strcpy(b_pre, token);
	o_cmd = b_pre_buffer(b_pre);
	strcpy(o_cmd, b_pre);
	chk_file = b_pre;
	chk_int = file_exist(chk_file);
	echo_chk = file_in_path_exist(chk_file);
	pre_pre = pre_fix(b_pre);
	count = 0;
	av[0] = pre_pre;
	while (count < (ac - 1) && argc <= ac)
	{
		count++;
		token = strtok(NULL, delim);
		av[count] = token;
	}
	count++;
	av[count] = NULL;
	if (chk_int == 0 && isatty(STDIN_FILENO))
		what_if(av);
	else if (echo_chk == 0 && isatty(!STDIN_FILENO))
		what_if(av);
	else
		printf("%s: 1: %s: not found\n", argv[0], o_cmd);
	wait(NULL);
	free(av);
}
	free_end(o_cmd, b_pre, str);
	return (0);
}
