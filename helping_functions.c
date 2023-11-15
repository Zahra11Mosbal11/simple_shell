#include "shell.h"

/**
 * argv_store - Store each token in the argv array
 *
 * @argv: Argv array pointer
 *
 * @str: String to tokenize.
 *
 * @delim: delemter
 *
 * Return: void
 */
void argv_store(char **argv, char *str, const char *delim)
{
	int i;
	char *token;

	token = strtok(str, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);

		token = strtok(NULL, delim);
	}
		argv[i] = NULL;
}

/**
 * _print - prints messages to screen.
 *
 * @msg: String to be printed.
 *
 * Return: void
 */
void _print(char *msg)
{
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * _memcpy - Check characters
 * @dest: An input character
 * @src: bytes
 * @n:  bytes to fill
 * Description: function swap words
 * Return: destination
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

/**
 * _strcmp - Check characters
 * @s1: An input character
 * @s2: source
 * Description: function compare words
 * Return: destination
 */
int _strcmp(const char *s1, const char *s2)
{
	/*int i = 0, strlength = 0;*/

	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++, s2++;
	}
	return (*s1 - *s2);

}

