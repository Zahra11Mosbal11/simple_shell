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
	char *dir, cwd[1024], cwd1[1024];
	int chdir_ret = -1;

	getcwd(cwd1, sizeof(cwd));
	if (!command[1])
	{
		dir = _getenv("HOME");
		if (!dir)
 			chdir_ret = chdir((dir = _getenv("PWD")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
		free(dir);
	}
	else if (_strcmp(command[1], "-") == 0)
	{
		dir = _getenv("OLDPWD");
		if (!dir)
		{
			_print(cwd1), _print("\n"), (*status) = 1;
 			free(dir);
			free_comd(command);
 			return;
		}
		_print(dir), _print("\n");
		chdir_ret = chdir(dir);
		free(dir);
	}
	else
		chdir_ret = chdir(command[1]);
	if (chdir_ret == -1)
	{
		_print("./hsh: 1: cd: can't cd to");
		_print(command[1]), _print("\n"), (*status) = 1;
		free_comd(command);
		return;
	}
	else if (chdir_ret != -1)
	{
		getcwd(cwd, sizeof(cwd));
		dir = _getenv("PWD");
		setenv("OLDPWD", dir, 1);
		setenv("PWD", cwd, 1);
		(*status) = 0;
	}
	free(dir);
	free_comd(command);
}
