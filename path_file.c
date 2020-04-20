#include "shell.h"
char *find_env_path(void);
/**
 *_path - find path of a specific command
 *@filename: name of the command
 *Return: path of a specific command if exit
 */
char *_path(char *filename)
{
	int i = 0;
	char *token, *list_path, *_path, *str_env, *slach = "/\0";

	str_env = find_env_path();
	token = strtok(str_env, "=");
	while (token)
	{
		token = strtok(NULL, ":");
		if (token)
		{
			list_path = malloc(sizeof(char) * (_strlen(token) +
				_strlen(filename) + 2));
			_strcpy(list_path, token);
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
		free(list_path), list_path = NULL;
		i++;
	}
	free(str_env), str_env = NULL;
	return (_path);
}
/**
 *find_env_path - extract path environ variable
 *Return: sting of path env variable
 */
char *find_env_path(void)
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
					str_path = _strdup(environ[i]);
					flag = 0;
				}
			}
		}
	}
	return (str_path);
}
