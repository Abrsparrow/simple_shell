#ifndef SHELL_H
#define SHELL_H
/* Standard library */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
/* Main FUnctions */
void executeCommand(char *command);
char **parseCommand(char *command);

#endif
