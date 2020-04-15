#include "shell.h"
/**
 *prompt_cmd - Display a prompt and wait for the user to type a command
 *Return: command entred by user
 */
char *prompt_cmd(void)
{
	size_t size = 0;
	int index;
	char *buff, *str, *token;
	if (isatty(STDIN_FILENO))
		printf("$: ");
	index = getline(&buff, &size, stdin);
	if (index == EOF)
	{
		free(buff);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	buff[index - 1] = '\0';
	token = strtok(buff, "/");
	while(token)
	{
		str = _strdup(token);
		token = strtok(NULL, "/");
		if (token)
		{
			free(str);
		}
	}
	free(buff);
	return (str);
}
