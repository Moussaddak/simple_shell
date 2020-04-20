#ifndef H_SHELL
#define H_SHELL

extern char **environ;
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_uitoa(unsigned int count);

char *prompt_cmd(void);
char *parsing_cmd(char **cmd);
char **store_args(char *buff, char *delims);
char *_path(char *filename);
unsigned int count_args(char *str, const char c);
void _error(int line, char **args, char *str);
void clear_memory(char **args);

#endif
