#include "shell.h"
/**
 * _unsetenv - to remove the environment variabl
 * @varName: the neme of environment variabl
 * Return: 0 in success
 */
void _unsetenv(char *varName)
{
	int i = 0, len = 0;

	if (!varName)
	{
		_print("Environment variable name not found.\n");
		return;
	}
	while (environ[i])
	{
		len = _strlen(varName);
		if (strncmp(environ[i], varName, len) == 0 && environ[i][len] == '=')
		{
			/* Found the environment variable, remove it */
			free(environ[i]);
			/* Shift the remaining variables to fill the gap */
			while (environ[i + 1] != NULL)
			{
				environ[i] = environ[i + 1];
				i++;
			}
			environ[i] = NULL;
			return;
		}
		i++;
	}
	_print("Environment variable not found.\n");
}
/**
 * _cd - to change directory
 * @command:  the command
 * @status: the status
 * Return: 0 in success
 */
void _cd(char **command, int *status)
{
	char *str, *dir = NULL, buffer[1024], *cwd_copy;
	int chdir_ret;

	str = getcwd(buffer, 1024);
	if (!command[1])
	{
		dir = _getenv("HOME");
		if (!dir)
			chdir_ret = chdir((dir = _getenv("PWD")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(command[1], "-") == 0)
	{
		if (!_getenv("OLDPWD"))
		{
			_print(str), _print("\n"), (*status) = 1;
			free_comd(command);
			return;
		}
		_print(_getenv("OLDPWD")), _print("\n");
		dir = _getenv("OLDPWD");
		chdir_ret = chdir(dir);
	}
	else
		chdir_ret = chdir(command[1]);
	if (chdir_ret == -1)
	{
		_print("cd: Cannot change directory to: ");
		_print(command[1]), _print("\n"), (*status) = 1;
	}
	else
	{
		cwd_copy = _strdup(getcwd(buffer, 1024));
		setenv("OLDPWD", _getenv("PWD"), 1);
		setenv("PWD", cwd_copy, 1);
		free(cwd_copy), (*status) = 0;
	}
	free(dir);
	free_comd(command);
}
/**
 * free_cwd - to free the cwd
 * @cwd: the env
 * Return: void
 */
void free_cwd(char *cwd)
{
	free(cwd);
}
