#include "shell.h"

/**
 * get_var - to handle variables
 * @command: the command
 * @status: the status
 * Return: void
 */

void get_var(char **command, int status)
{
	if (_strcmp(command[1], "$?") == 0)
	{
		printInt(WEXITSTATUS(status));
	}
	else
		if (_strcmp(command[1], "$$") == 0)
		{
			printInt(getpid());
		}
}
