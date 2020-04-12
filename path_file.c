#include "shell.h"
char* find_env_path(void);
/**
 *_path - find path of a specific command
 *@filename: name of the command
 *Return: path of a specific command if exit
 */
char* _path(char *filename)
{
	int i = 0;
	char *token, **list_path, *_path, *str_env;

one_more_time:
	list_path = malloc(sizeof(char *) * 1024);
	if (!list_path)
	{
		goto one_more_time;
	}
	str_env = find_env_path();
	token = strtok(str_env, "=");
	while (token)
	{
		token = strtok(NULL, ":");
		list_path[i] = token;
		i++;
	}
	for (i = 0; list_path[i]; i++)
	{
		_path = _strcat(list_path[i], _strcat("/", filename));
		if (access(_path, F_OK) == 0)
		{
			free(list_path);
			return (_path);
		}
	}
	return (NULL);
}
/**
 *find_env_path - extract path environ variable
 *Return: sting of path env variable
 */
char* find_env_path(void)
{
	int i = -1, j, flag = 1;
	char *str_path, *target = "PATH";

	while (environ[++i] && flag)
	{
		if (environ[i][0] == target[0])
		{
			for (j = 1; j < 3; j++)
			{
				if (environ[i][j] != target[j])
				{
					break;
				}
				else if (environ[i][2] == target[2])
				{
again:
					str_path = _strdup(environ[i]);
					if (!str_path)
					{
						goto again;
					}
					flag = 0;
				}
			}
		}
	}
	return (str_path);
}
