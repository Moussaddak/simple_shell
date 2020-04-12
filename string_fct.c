#include "shell.h"
/**
 *_strcat - concatinate two strings together
 *@src: input
 *@dest: input
 *Return: a string
 */
char *_strcat(char *dest, char *src)
{
	char *str = dest;

	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (str);
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
