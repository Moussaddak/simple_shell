#include "shell.h"
/**
 *main - shell program
 *@argc: not used
 *@argv: name of program
 *Return: 0
 **/
int main(int argc __attribute__((unused)), char **argv)
{
	char *buff, delims[] = " ", *str, *error, **args;
	int line = 0;
	pid_t pid = 0;

	while (1)
	{
		line++;
		buff = prompt_cmd();
		args = store_args(buff, delims);
		buff = NULL;
		buff = parsing_cmd(args);
		if (buff)
		{
			str = _path(args[0]);
			error = strdup(args[0]);
			free(args[0]), args[0] = NULL;
			args[0] = _strdup(str);
			free(str), str = NULL;
			if (!args[0])
			{
				_error(line, &argv[0], error);
				free(error), error = NULL;
			}
			else
			{
				free(error), error = NULL;
				pid = fork();
				if (pid == 0)
				{
					execve(args[0], args, NULL);
				}
				else if (pid > 0)
					waitpid(pid, NULL, 0);
			}
		}
		clear_memory(args);
	}
	return (0);
}
