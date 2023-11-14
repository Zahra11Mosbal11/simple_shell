#include "shell.h"


/**
 * _isdigit - Check characters
 * @c: An input character
 * Return: 1 if digit or 0 if not
*/
int _isdigit(char c)
{
	int digit = 0;
	char i;

	for (i = '0'; i <= '9'; i++)
	{
		if (c == i)
		{
			digit = 1;
			break;
		}
	}
	return (digit);
}

/**
 * only-digit - Check string
 * @c: An input string
 * Return: 1 if digit or 0 if not
*/
int only-digit(char *c)
{
	while (*c)
		if (_isdigit(*c++) == 0)
			return (0);
	return (1);
}

/**
 * _atoi - Check characters
 * @s: An input string
 * Return: int of string
*/
int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;
	char f = 0;

	if (*s == '-')
			sign *= -1;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{
			f = 1;
			num = num * 10 + *s - '0';
		}

		else if (f)
			break;
		s++;
	}

	if (sign < 0)
		num = (-num);

	return (num);
}
