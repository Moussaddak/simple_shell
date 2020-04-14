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

	printf("list_path at begin : %s\n",list_path);
	printf("list_path : %p\n",list_path);
	index = find_env_path();
	printf("index : %d\n",index);
	str_env = malloc(sizeof(char) * _strlen(environ[index]) + 1);
	_strcpy(str_env, environ[index]);
	printf("str_env : %s \n", str_env);
	token = strtok(str_env, "=");
	printf("token %s\n",token);
	printf("i : %d\n",i);
	while (token)
	{
		printf("i after while : %d\n",i);
		token = strtok(NULL, ":");
		printf("token after while %s \n",token);
		if (token)
		{
			list_path = _strdup(token);
			printf("list_path : %s \n",list_path);
			_path = _strcat(_strcat(list_path, slach), filename);
			printf("path : %s\n",_path);
			if (access(_path, F_OK) == 0)
			{
				printf("file found\n");
				break;
			}
		}
		else
			_path = NULL;
		free(list_path);
		printf("list_path after free : %s\n",list_path);
		i++;
	}
	free(str_env);
	printf("fin de path_finder\n");
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
