#include "shell.h"
/**
 * _read - start
 * Return: the input
 */
char *_read(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		_print("$ ");
	n = getline(&input, &len, stdin);
	if (n == -1)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
/**
 * token_shz - to do the token
 * @input: the user command
 * Return: the command after token
 */
char **token_shz(char *input)
{
	char *tok = NULL, *cp_input =  _strdup(input), **user_cmad =  NULL;
	int cpi = 0, i = 0;
	const char *delimit = " \t\n";

	if (!input)
		return (NULL);
	tok = strtok(cp_input, delimit);
	if (tok == NULL)
	{
		free(input);
		free(cp_input);
		return (NULL);
	}
	while (tok)
	{
		cpi++;
		tok = strtok(NULL, delimit);
	}
	user_cmad = malloc(sizeof(char *) * (cpi + 1));
	if (!user_cmad)
	{
		free(input);
		free(cp_input);
		return (NULL);
	}
	tok = strtok(input, delimit);
	while (tok)
	{
		user_cmad[i] = _strdup(tok);
		if (!user_cmad[i])
		{
			free_comd(user_cmad);
			free(cp_input);
			return (NULL);
		}
		tok = strtok(NULL, delimit);
		i++;
	}
	free(cp_input);
	free(input);
	user_cmad[i] = NULL;
	return (user_cmad);
}
/**
 * execute_comd - to do the execution
 * @user_comd: the command
 * @argv: the argommant
 * Return: the status
 */
int execute_comd(char **user_comd, char **argv)
{
	char *exe_file_path;
	pid_t chip;
	int status;

	exe_file_path = search_path(user_comd[0]);
	if (!exe_file_path)
	{
		_printerr(argv[0], user_comd[0]);
		free_comd(user_comd);
		return (127);
	}

	chip = fork();
	if (chip == 0)
	{
		if (execve(exe_file_path, user_comd, environ) == -1)
		{
			free(exe_file_path);
			free_comd(user_comd);
		}
	}
	else
	{
		waitpid(chip, &status, 0);
		free_comd(user_comd);
		free(exe_file_path);
	}
	return (WEXITSTATUS(status));
}
/**
 * free_comd - to free
 * @comd: the array of command
 * Return: void
 */
void free_comd(char **comd)
{
	int i;

	if (!comd)
		return;
	for (i = 0; comd[i]; i++)
		free(comd[i]), comd[i] = NULL;
	free(comd), comd = NULL;
}
/**
 * _printerr - to handle the error
 * @name: the name of shell
 * @comd: the command
 * Return: void
 */
void _printerr(char *name, char *comd)
{
	_print(name);
	_print(": ");
	_print("1");
	_print(": ");
	_print(comd);
	_print(": ");
	_print("not found\n");
}
