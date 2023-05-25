#ifndef MAIN_H
#define MAIN_H

extern char **environ;

int compareStrings(const char *str1, const char *str2);

void print_environment(void);

int count_spaces(char *input);

int file_exist(const char *filename);

int file_in_path_exist(const char *filename);

char *pre_fix(char *str);

void ter_minate(int sig);

char **av_buffer(int ac, char *str);

char *b_pre_buffer(char *tok);

int what_if(char *av[]);

#endif
