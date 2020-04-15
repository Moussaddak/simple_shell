#include "shell.h"
int find_env_path(void);
/**
 *_path - find path of a specific command
 *@filename: name of the command
 *Return: path of a specific command if exit
 */
char *_path(char *filename)
{
	int i = 0, index;
	char *token = NULL, *list_path = NULL, *_path, *str_env, *slach = "/\0";

	index = find_env_path();
	str_env = malloc(sizeof(char) * _strlen(environ[index]) + 1);
/* handle malloc */
	_strcpy(str_env, environ[index]);
	token = strtok(str_env, "=");
	while (token)
	{
		token = strtok(NULL, ":");
		if (token)
		{
			list_path = _strdup(token);
			_path = _strcat(_strcat(list_path, slach), filename);
			if (access(_path, F_OK) == 0)
			{
				break;
			}
		}
		else
		{
			_path = NULL;
			break;
		}
		free(list_path);
		i++;
	}
	free(str_env);
	return (_path);
}
/**
 *find_env_path - extract path environ variable index
 *Return: index of path env variable
 */
int find_env_path(void)
{
	int i = 0, j, index, flag = 1;
	char *target = "PATH";

	while (environ[i++] && flag)
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
					index = i;
					flag = 0;
				}
			}
		}
	}
	return (index);
}
