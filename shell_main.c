#include "shell.h"
/**
 * main - Runs a simple UNIX command interpreter.
 * @ac: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0.
 */
int main(int ac, char **argv)
{
	char *input = NULL, **user_comd = NULL, *input1 = NULL;
	int status = 0;
	(void) ac;

	while (1)
	{
		input = _read();
		if (input == NULL) /* Ctrl+D */
		{
			if (isatty(STDIN_FILENO))
				_print("\n");
			return (status);
		}

		input1 = _comment(input);
		user_comd = token_shz(input1);

		if (!user_comd)
			continue;

		if (user_comd[0] != NULL && check_built(user_comd[0]))
			get_builtin(user_comd, argv, &status);
		else
			if ((_strcmp(user_comd[0], "echo") == 0) &&
		(_strcmp(user_comd[0], "$$") || _strcmp(user_comd[0], "$?")))
				get_var(user_comd, status);
			else
				if (user_comd[0] != NULL)
					status = execute_comd(user_comd, argv);
	}

}
