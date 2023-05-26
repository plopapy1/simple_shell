#ifndef MAIN_H
#define MAIN_H

extern char **environ;

char **ac_malloc(int ac, char *str);

char *r_newline(char *str);

void taskone(char **arg, char **env);

void remove_spaces(char *str);

char *search_path(char *command, char **env);

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
