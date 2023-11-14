#include "shell.h"
/**
 * check_built - to check the builtins
 * @command: the command
 * Return: 1 if success
 */
int check_built(char *command)
{
	char *bui[] = { "exit", "env", NULL };

	int i;
	for (i = 0; bui[i]; i++)
	{
		if (_strcmp(command, bui[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 * get_builtin - to handle all builtin
 * @command: the command
 * @status: the status
 * @argv: the argmment
 * Return: void
 */
void get_builtin(char **command, char **argv, int *status)
{
	if (_strcmp(command[0], "exit") == 0)
		exit_sh(command, argv, status);
	else if (_strcmp(command[0], "env") == 0)
		print_env(command, status);

}
/**
 * exit_sh - to exit from the shell
 * @command:  the command
 * @argv: the argmment
 * @status: the status
 * Return: void
 */
void exit_sh(char **command,  char **argv, int *status)
{
	int stat = 0;

	(void) argv;
	(void) status;
	
	if (command[1] == NULL)
	{
		exit(stat);
	}
	else
		if (only_digit(command[1]))
		{
			stat = _atoi(command[1]);
			printf("exit");
			free_comd(command);
			exit(stat);
		}
		else
			perror("Illegal number");
}
/**
 * print_env - that print the each environment variable
 *
 * @command:  the command
 * @status: the status
 * Return: void;
 */
void print_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_comd(command);
	(*status) = 0;
}
