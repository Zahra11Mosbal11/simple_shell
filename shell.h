#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define BUF 1024

extern char **environ;

/* toem_string.c */

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *sec);
char *_strdup(const char *str);
void _print(char *msg);
/*main functions*/
char *_read(void);
char **token_shz(char *input);
void free_comd(char **comd);
int execute_comd(char **user_comd, char **argv);
void _printerr(char *name, char *comd);
char *_getenv(char *env_var);
char *search_path(char *command);
/*handle builtin*/
void get_builtin(char **command, char **argv, int *status);
void exit_sh(char **command,  char **argv, int *status);
void print_env(char **command, int *status);
int check_built(char *command);
void _setenv(char *varName, char *varValue, int overwrite);
void _unsetenv(char *varName);
void _cd(char **command, int *status);

int _isdigit(char c);
int only_digit(char *c);
int _atoi(char *s);
char *_comment(char *input);
char *_strstr(char *haystack, char *needle);

#endif /* SHELL_H */

