#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

/*main functions*/
void execute_command(char **argv);
char *search_path(char *command);

/*helping functions*/
/*String functions*/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
int strtoknum(char *str, const char *delim);
char *_strdup(char *s);
int _strncmp(char *cs, char *ct, size_t count);
int _strcmp(char *s1, char *s2);/*in helping file*/

/*other functions*/
void argv_store(char **argv, char *str, const char *delim);
void _print(char *msg);
char *_memcpy(char *dest, char *src, unsigned int n);

/*handle builtin*/
void print_env(void);
int get_builtin(char **argv);
char *_getenv(char *env_var);
int _setenv(char *varName, char *varValue, int overwrite);
#endif /* SHELL_H */
