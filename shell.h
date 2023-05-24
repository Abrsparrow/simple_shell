#ifndef SHELL_H
#define SHELL_H
/* Standard library */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

/* define Types */
extern char **environ;
/* helper_function */
int _strlen(char *s);
/* Main Functions */
void executeCommand(char *command);
char **parseCommand(char *command);

#endif
