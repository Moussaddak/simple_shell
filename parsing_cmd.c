#include "shell.h"
/**
 *parsing_cmd - select option exit or display env or return command
 *@cmd: user typed command
 *Return: command line
 */
char *parsing_cmd(char **cmd)
{
	int i;

	if (!_strcmp(cmd[0], "exit"))
	{
		clear_memory(cmd);
		exit(EXIT_SUCCESS);
	}
	else if (!_strcmp(cmd[0], "env"))
	{
		for (i = 0 ; environ[i] ; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		clear_memory(cmd);
		return (NULL);
	}
	else
	{
		return (cmd[0]);
	}
}
