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
 * @name: the name of directory
 * Return: 0 in success
 */
void _cd(char *name)
{
	char pr_dir[BUF];
	char cwd[BUF];

	if (_strcmp(name, "-") == 0)
	{/* Handle 'cd -'*/
		if (pr_dir[0] != '\0')
		{
			_print(pr_dir); /* Print the directory being switched to*/
			_print("\n");
			if (chdir(pr_dir) != 0)
			{
				_print("cd: Cannot change directory \n");
				return;
			}
		}
		else
		{
			_print("cd: No previous directory to switch to\n");
			return;
		}
	}
	else
	{
		if (chdir(name) != 0)/*change directory*/
		{
			_print("cd: Cannot change directory \n");
			return;
		}
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		_print("cd: Error getting current working directory\n");
		return;
	}
	_strcpy(pr_dir, cwd);
	update_pwd(cwd);
}
/**
 * update_pwd - to update current working directory
 * @pwd_new: the new pwd
 * Return: void
 */
void update_pwd(char *pwd_new)
{
	if (pwd_new == NULL)
	{
		_print("cd: Error updating PWD\n");
		return;
	}

	_setenv("PWD", pwd_new, 1);
}
