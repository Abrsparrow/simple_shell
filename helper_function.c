#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */

int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
	i++;
	}
	return (i);
}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if equal
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
	if (*s1 == '\0')
	{
		return (0);
	}
	s1++;
	s2++;
	}
	return (*s1 - *s2);
}
