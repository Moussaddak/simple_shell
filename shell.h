#ifndef H_SHELL
#define H_SHELL

#define _POSIX_C_SOURCE 200809L

extern char **environ;

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _puts(const char *str);
int _putchar(char c);

char *prompt_cmd(void);
char *parsing_cmd(char *cmd);
char **store_args(char *buff, char *delims);
char *_path(char *filename);
unsigned int count_args(char *str, const char c);
int fork_process(char **args);

#endif
