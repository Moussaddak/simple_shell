#include "shell.h"
int main(void)
{
	char *buff, delims[] = " ", *token, *str;
	char **args;
	int nb;
	size_t size = 0, i = 0, index;
	pid_t pid;

	while (1)
	{
		printf("$: ");
		index = getline(&buff, &size, stdin);
		buff[index - 1] = '\0';
		printf("buff : %s\n",buff);
		if (!_strcmp(buff, "exit"))
		{
			for (i = 0; args[i]; i++)
			{
				free(args[i]);
			}
			free(args);
			free(buff);
			exit(0);
		}
		nb = count_args(buff, ' ');
		token = strtok(buff, delims);
	again:
		args =  malloc(sizeof(char *) * nb);
		if (!args)
		{
			goto again;
		}
		args[i++] = _strdup(token);
		while (token)
		{
			token = strtok(NULL, delims);
			args[i] = _strdup(token);
			i++;
		}
		str = _strdup(_path(args[0]));
		_strcpy(args[0], str);
		free(str);
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

			free(buff);
		}
	}
	return (0);
}
