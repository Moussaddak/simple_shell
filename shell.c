#include "shell.h"

/**
 *main - entry point
 *
 *Return: 0 on success
 */
int main(void)
{
char *buff, delims[] = " \t\r\n\a", *str, *error;
char **args;

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
_puts(" command not found");
_puts("\n");
goto begin;
}
free(error);
fork_process(args);
}
return (0);
}
