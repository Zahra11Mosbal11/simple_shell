#include "main.h"
/**
 * print_sh - to print string that send to it
 *
 * @str: the string we want to print
 *
 * Return: void
 */
void print_sh(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
