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

void handle_line_commands(char *line)
{
    char *token, *arg_token;
    char *command[MAX_ARGUMENTS];
    int i = 0;

    // Split the line by semicolon (;)
    token = strtok(line, ";");

    while (token != NULL) {
        i = 0;
        // Split each command by space
        arg_token = strtok(token, " ");
        while (arg_token != NULL && i < MAX_ARGUMENTS - 1) {
            command[i] = arg_token;
            arg_token = strtok(NULL, " ");
            i++;
        }
        command[i] = NULL;
        
        execute_command(command);

        token = strtok(NULL, ";");
    }
}

int multi_command (char *command)
{
	char *token;
	
	token = strtok(line, ";");
	if (token != NULL)
		return (1);
	return (0);
}