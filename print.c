#include "shell.h"

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
