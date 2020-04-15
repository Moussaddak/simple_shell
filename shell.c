#include "shell.h"
int main(void)
{
	char *buff, delims[] = " ", *str, *error;
	char **args;

	size_t i = 0;
	pid_t pid;

	while (1)
	{
	begin:
		buff = prompt_cmd();
		buff = parsing_cmd(buff);
		if (!buff)
			goto begin;
		args = store_args(buff, delims);
		str = _path(args[0]);
		error = _strdup(args[0]);
		free(args[0]);
		args[0] = _strdup(str);
		free(str);
		if (!args[0])
		{
			write(STDOUT_FILENO, error, _strlen(error));
			free(error);
			printf(" :command not found\n");
			goto begin;
		}
		free(error);
		pid = fork();
		if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				printf("Command invoked cannot execute\n");
				goto begin;
			}
		}
		else if (pid > 0)
		{
			waitpid(pid, NULL, 0);
			for (i = 0; args[i]; i++)
				free(args[i]);
			free(args);
			free(buff);
		}
	}
	return (0);
}
