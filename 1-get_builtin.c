#include "shell.h"
/**
 * _cd - to change directory
 * @name: the name of directory
 * Return: 0 in success
 */
int _cd(char *name)
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
				return (0);
			}
		}
		else
		{
			_print("cd: No previous directory to switch to\n");
			return (0);
		}
	}
	else
	{
		if (chdir(name) != 0)/*change directory*/
		{
			_print("cd: Cannot change directory \n");
			return (0);
		}
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		_print("cd: Error getting current working directory\n");
		return (0);
	}
	_strcpy(pr_dir, cwd);
	update_pwd(cwd);
	return (0);
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

	if (_setenv("PWD", pwd_new, 1) != 0)
	{
		_print("cd: Error updating PWD\n");
	}

}
