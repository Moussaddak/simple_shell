#include "shell.h"

/**
 *fork_process - create a child process
 *@args: argument
 *
 *Return: 0 on success
 */

int fork_process(char **args)
{
char *buff = NULL;
pid_t pid;
int i;

pid = fork();
if (pid == 0)
{
if (execve(args[0], args, environ) == -1)
{
perror("Command invoked cannot execute\n");
}
exit(EXIT_FAILURE);
}
else if (pid > 0)
{
waitpid(pid, NULL, 0);
for (i = 0; args[i]; i++)
free(args[i]);
free(args);
free(buff);
}
return (0);
}
