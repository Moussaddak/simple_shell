#include "shell.h"
/**
 *clear_memory - free heap memory
 *@args: input
 */
void clear_memory(char **args)
{
	int i;

	if (args && *args)
	{
		for (i = 0; args[i]; i++)
		{
			free(args[i]), args[i] = NULL;
		}
		free(args),args = NULL;
	}
}
