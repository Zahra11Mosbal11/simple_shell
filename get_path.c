#include "shell.h"
/**
 * search_path - search command path in environment path.
 * @command: command to search for.
 * Return: command full path.
 */
char *search_path(char *command)
{
	char *path, *path_cp, *token, *exe_file_path;
	int cmd_len, dir_len;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_cp = _strdup(path);
		cmd_len = _strlen(command);
		/* Let's break down the path variable and get all the directories available*/
		token = strtok(path_cp, ":");
		while (token != NULL)
		{
			dir_len = _strlen(token);
			exe_file_path = malloc(cmd_len + dir_len + 2);
			/* build command by copying directory path and concatenate command*/
			_strcpy(exe_file_path, token);
			_strcat(exe_file_path, "/");
			_strcat(exe_file_path, command);
			_strcat(exe_file_path, "\0");
			if (stat(exe_file_path, &buffer) == 0)
			{
				free(path_cp);
				return (exe_file_path);
			}
			else
			{
				free(exe_file_path);
				token = strtok(NULL, ":");
			}
		}
		free(path_cp);
		/* before exit check if the command itself is a exe_file_path that exists*/
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
