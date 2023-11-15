#include "shell.h"
/**
 * *_getenv - Check if the environment variable already exists
 * @env_var: the name of environment variable
 * Return: the value of it
 */
char *_getenv(char *env_var)
{
	int i = 0;
	char *key, *_cp, *valu, *env;

	while (environ[i])
	{
		/* Tokenize the environment variable using "=" as the delimiter*/
		_cp = _strdup(environ[i]);
		key = strtok(_cp, "=");

		if (_strcmp(key, env_var) == 0)
		{/*Compare the key with the target environment variable name*/

			valu = strtok(NULL, "\n");
			env = _strdup(valu);
			free(_cp);
			return (env);
		}
		free(_cp);
		i++;
	}
	/* If the environment variable is not found, return NULL*/
	return (NULL);
}
/**
 * search_path - search command path in environment path.
 * @command: command to search for.
 * Return: command full path.
 */
char *search_path(char *command)
{
	char *path, *path_dr, *exe_file_path;
	int i;
	struct stat buf;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &buf) == 0)
				return (_strdup(command));

			return (NULL);
		}
	}
	path = _getenv("PATH");
	if (!path)
		return (NULL);
	path_dr = strtok(path, ":");
	while (path_dr)
	{
		exe_file_path = malloc(_strlen(path_dr) + _strlen(command) + 2);
		if (exe_file_path)
		{
			_strcpy(exe_file_path, path_dr);
			_strcat(exe_file_path, "/");
			_strcat(exe_file_path, command);
			if (stat(exe_file_path, &buf) == 0)
			{
				free(path);
				return (exe_file_path);
			}
			free(exe_file_path);
		}
		path_dr = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
