#include "shell.h"
/**
 *parsing_cmd - select option exit or display env or return command
 *@cmd: user typed command
 *Return: command line
 */
char *parsing_cmd(char *cmd)
{
	int i;

	if (!_strcmp(cmd, "exit"))
	{
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	else if (!_strcmp(cmd, "env"))
	{
		for (i = 0 ; environ[i] ; i++)
		{
			_puts(environ[i]);
			_puts("\n");
		}
		return (NULL);
	}
	else
	{
		return (cmd);
	}
}
