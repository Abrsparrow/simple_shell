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
#define MAX_ALIASES 100
#define MAX_ALIAS_NAME 100
#define MAX_ALIAS_VALUE 100
/**
 * struct Alias - Structure to store an alias mapping.
 * @name: The name of the alias.
 * @value: The value of the alias.
 *
 * Description: This structure represents an alias mapping, which consists
 * of a name and its corresponding value.
 */
typedef struct Alias
	{
	char name[MAX_ALIAS_NAME];
	char value[MAX_ALIAS_VALUE];
	} Alias;
/* helper_function */
int _strlen(const char *s);
int _strcmp(const char *s1, const char *s2);
/* Main Functions */
int executeCommand(char *command);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
#endif
