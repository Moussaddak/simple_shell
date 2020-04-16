#include "shell.h"
/**
 *store_args - store all arguments entred in array
 *@buff: string of command line
 *@delims: list of character
 *Return: array of argument
 */
char **store_args(char *buff, char *delims)
{
	char **args, *token;
	int nb, i = 0;

	nb = count_args(buff, ' ');
	token = strtok(buff, delims);
	args =  malloc(sizeof(char *) * nb);
	if (args == NULL)
	  {
	    return (NULL);
	    exit(EXIT_FAILURE);
	  }
	/* handle malloc allocation*/
	args[i++] = _strdup(token);
	while (token)
	{
		token = strtok(NULL, delims);
		args[i] = _strdup(token);
		i++;
	}
	return (args);
}
