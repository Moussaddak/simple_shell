#include "shell.h"
/**
 *store_args - store all arguments entred in array
 *@buff: string of command line
 *@delims: list of character
 *Return: array of argument
 */
char **store_args(char *buff, char *delims)
{
	char **args, *token, *str;
	int nb, i = 0;

	nb = count_args(buff, ' ');
	token = strtok(buff, delims);
	args =  malloc(sizeof(char *) * (nb + 1));
	/* handle malloc allocation error*/
	args[i] = _strdup(token);
	while (token && ++i)
	{
		token = strtok(NULL, delims);
		if (token)
		{
			args[i] = _strdup(token);
		}
	}
	args[i] = NULL;
	if (count_args(args[0], '/') > 1)
	{
		token = strtok(args[0], "/");
		while (token)
		{
			str = _strdup(token);
			token = strtok(NULL, "/");
			if (token)
			{
				free(str), str = NULL;
			}
		}
		free(args[0]), args[0] = NULL;
		args[0] = _strdup(str);
		free(str), str = NULL;
	}
	free(buff), buff = NULL;
	return (args);
}
