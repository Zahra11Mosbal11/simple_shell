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

/**
 * _printerr - to handle the error
 * @name: the name of shell
 * @comd: the command
 * Return: void
 */
void _printerr(char *name, char *comd)
{
	char *str;

	str = name;
	_strcat(str, ": 1: ");
	_strcat(str, comd);
	_strcat(str, ": not found\n");
	write(STDERR_FILENO, str, _strlen(str));
}


/**
 * printInt - to handle the int printing
 * @num: the number to be printed
 * Return: void
 */

void printInt(int num)
{
	char buffer[20];
	int length = 0;
	int isNegative = 0;
	int i;

	if (num < 0)
	{
		isNegative = 1;
		num = -num;
	}
	buffer[length++] = '0' + (num % 10);
	num /= 10;
	while (num > 0)
	{
		buffer[length++] = '0' + (num % 10);
		num /= 10;
	}
	if (isNegative)
	{
		buffer[length++] = '-';
	}
	for (i = 0; i < length / 2; i++)
	{
		char temp = buffer[i];

		buffer[i] = buffer[length - i - 1];
		buffer[length - i - 1] = temp;
	}
	write(1, buffer, length);
	write(1, "\n", _strlen("\n"));
}
