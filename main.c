#include "shell.h"
/**
 *
 *
 */
int main(void)
{
	char *buff, delims[] = " ", *token;
	char **args;
	int nb;
	size_t size = 0, i = 0, index;
	pid_t pid;

	while (1)
	{
		printf("$: ");
		index = getline(&buff, &size, stdin);
		buff[index - 1] = '\0';
		if (!_strcmp(buff, "exit"))
		{
			free(args);
			exit(0);
		}
		nb = count_args(buff);
		token = strtok(buff, delims);
again:
		args =  malloc(sizeof(char *) * nb);
		if (!args)
		{
			goto again;
		}
		args[i++] = token;
		while (token)
		{
			token = strtok(NULL, delims);
			args[i] = token;
			i++;
		}
		args[0] = _path(args[0]);
		pid = fork();
		if (pid == 0)
		{
			printf("child 1 executed\n");
			if (execve(args[0], args, NULL) == -1)
			{
				printf("Error 1\n");
				exit(0);
			}
		}
		else if (pid > 0)
		{
			waitpid(pid, NULL, 0);
		}
	}
	return (0);
}
