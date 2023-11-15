#include "shell.h"
/**
 * _strncmp - Compare two length-limited strings
 * @cs: One string
 * @ct: Another string
 * @count: The maximum number of bytes to compare
 * Return: 0 in success
 */
int _strncmp(char *cs, char *ct, size_t count)
{
	unsigned char c1, c2;

	while (count > 0)
	{
		c1 = *cs++;
		c2 = *ct++;
		if (c1 != c2)
			return (c1 < c2 ? -1 : 1);
		if (c1 == '\0')
			break;
		count--;
	}

	return (0);
}
