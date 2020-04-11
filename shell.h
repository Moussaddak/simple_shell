#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#define B_BUFSIZE 1024
#define B_BBUFSIZE 128
#define B_DELIM "' '|='\t\r\n\a#\"&*`" 


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

void shell_loop(void);
char *read_cmd(void);
char **parse_cmd(char *line);
int shell_execute(char **argument);


#endif
