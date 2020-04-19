#include "shell.h"
/**
 *_strcat - concatinate two strings together
 *@src: input
 *@dest: input
 *Return: a string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	i = _strlen(dest);

	while (*(src + j) != '\0')
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
	}
	*(dest + i) = '\0';
	return (dest);
}
/**
 *_strdup -  duplicate of the string pointed to by str
 *@str: input
 *Return: string
 */
char *_strdup(char *str)
{
	int i = 0, j = 0;
	char *cp;

	if (str == NULL)
	{
		return (NULL);
	}

	while (*(str + i) != '\0')
	{
		i++;
	}

	cp = malloc(i * sizeof(char) + 1);

	if (cp == NULL)
	{
		return (NULL);
	}

	while (*(str + j) != '\0')
	{
		cp[j] = str[j];
		j++;
	}

	*(cp + j) = '\0';

	return (cp);
}
/**
 *_strcmp - compare strings
 *@s1: string
 *@s2: string
 *
 *Return: integer j
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int j = 0;

	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	j += s1[i] - s2[i];
	return (j);
}
/**
 *_strlen - prints the length of a string
 *@s: input
 *Return: integer
 */
int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	else
		return (1 + _strlen(s + 1));
}
/**
 *_uitoa - convert an integer to string
 *@count: integer to be converted
 *Return: string
 */
char *_uitoa(unsigned int count)
{
	char *numstr = NULL;
	unsigned int tmp = 0, digits = 0;

	tmp = count;
	for (digits = 0; tmp != 0; digits++)
	{
		tmp /= 10;
	}
	numstr = malloc(sizeof(char) * (digits + 1));
	if (numstr == NULL)
	{
		perror("Fatal Error");
		exit(127);
	}
	numstr[digits] = '\0';
	for (--digits; count; --digits)
	{
		numstr[digits] = (count % 10) + '0';
		count /= 10;
	}
	return (numstr);
}
