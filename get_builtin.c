#include "shell.h"
/**
 * check_built - to check the builtins
 * @command: the command
 * Return: 1 if success
 */
int check_built(char *command)
{
	char *bui[] = { "exit", "env", "setenv", "unsetenv", "cd", NULL };
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
	else if (_strcmp(command[0], "setenv") == 0)
	{
		if (command[1] == NULL || command[2] == NULL)
		{
			_print("setenv: Invalid variable name or the value\n");
			free_comd(command);
			(*status) = 0;
		}
		else
		{

			char *name = command[1], *value = command[2];
			int overwrite = 0;

			if (_getenv(name) != NULL)
				overwrite = 1;
			_setenv(name, value, overwrite);
			free_comd(command);
			(*status) = 0;
		}
	}
	else if (_strcmp(command[0], "unsetenv") == 0)
	{
		char *name = command[1];

		_unsetenv(name);
		free_comd(command);
		(*status) = 0;
	}
	else if (_strcmp(command[0], "cd") == 0)
	{
		if (command[1] == NULL)
			chdir(_getenv("HOME"));
		else
		{
			char *ch_dir = command[1];

			_cd(ch_dir);
		}
		free_comd(command);
		(*status) = 0;
	}

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
	int stat = (*status);
	char * str;
	
	if (!command[1])
	{
		free_comd(command);
		(*status) = 0;
		exit(stat);
	}
	else
	{
		if (only_digit(command[1]))
		{
			stat = _atoi(command[1]);
		}
		else
		{
			stat = 2;
			str = argv[0] ;
			_strcat(str, ": 1: ");
			_strcat(str, "exit: Illegal number: ");
			_strcat(str, command[1]);
			_strcat(str, "\n");
			write(STDERR_FILENO, str, _strlen(str));
			free_comd(command);
			(*status) = 2;
			return;
		}
		free_comd(command);
		exit(stat);
	}
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
/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @varName: name of environment variable
 * @varValue: value of environment variable
 * @overwrite: 1 if if the environment variable already exists
 * Return: 0 in success
 */
void _setenv(char *varName, char *varValue, int overwrite)
{
	int i = 0, len = 0;
	char *new_env;

	while (environ[i])
	{
		len = _strlen(varName);
		if (strncmp(environ[i], varName, len) == 0)
		{
			if (overwrite)
			{
				free(environ[i]); 

				new_env = malloc(_strlen(varName) + _strlen(varValue) + 2);
				_strcpy(new_env, varName);
				_strcat(new_env, "=");
				_strcat(new_env, varValue);

				environ[i] = new_env;
				return;
			}
			return;
		}
		i++;
	}

	new_env = malloc(_strlen(varName) + _strlen(varValue) + 2);
	_strcpy(new_env, varName);
	_strcat(new_env, "=");
	_strcat(new_env, varValue);
	environ[i] = new_env;
	environ[i + 1] = NULL;
}
