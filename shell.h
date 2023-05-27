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
#define MAX_COMMAND_LENGTH 100

/* helper_function */
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
/* Main Functions */
int executeCommand(char *command);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
#endif
