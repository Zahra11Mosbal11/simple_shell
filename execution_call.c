#include "shell.h"

/**
 * execute_command - execute command.
 *
 * @argv: array with full command.
 * Return: command full path.
 */

void execute_command(char **argv)
{
	char *command = NULL, *exe_command = NULL;
	pid_t cpid = fork();

	if (cpid == -1)
	{
		_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (cpid == 0)
	{

		if (argv)
		{
			/* get the command */
			command = argv[0];

			/* generate the path to this command before passing it to execve */
			exe_command = search_path(command);

			/* execute the actual command with execve */
			if (execve(exe_command, argv, NULL) == -1)
			{
				perror("Error:");
			}
		}

	}
	else
	{
		/* Parent process*/
		wait(NULL);
	}

}
