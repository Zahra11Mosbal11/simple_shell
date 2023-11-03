#include "main.h"
/**
 * main - entry
 *
 * @ac: the number of arg
 * @argv: the array or arg
 *
 * Return: 0 (success)
 */
int main(int ac, char **argv)
{
	char *inputptr = NULL, *inputptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int i;

	/* declaring void variables */
	(void)ac;

	/* Create a loop for the shell's prompt */
	while (1) 
	{
		print_sh("$ ");
		nchars_read = getline(&inputptr, &n, stdin);
		/* check if the getline function failed or reached EOF or user use CTRL + D */ 
		if (nchars_read == -1)
		{
			print_sh("Exiting shell....\n");
			return (-1);
		}
		/* allocate space for a copy of the inputptr */
		inputptr_copy = malloc(sizeof(char) * nchars_read);
		if (inputptr_copy== NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		/* copy inputptr to inputptr_copy */
        strcpy(inputptr_copy, inputptr);

	/********** split the string (inputptr) into an array of words ********/
	/* calculate the total number of tokens */
	token = strtok(inputptr, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;

	/* Allocate space to hold the array of strings */
	argv = malloc(sizeof(char *) * num_tokens);

	/* Store each token in the argv array */
	token = strtok(inputptr_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	/* execute the command */
	execmd(argv);
	}

	/* free up allocated memory */
	free(inputptr_copy);
	free(inputptr);

	return (0);
}
