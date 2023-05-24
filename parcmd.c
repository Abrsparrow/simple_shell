#include "shell.h"
/**
 * parseCommand - Parse the command and return the argument array
 * @command: The command to parse
 *
 * Return: The argument array
 */
char **parseCommand(char *command)
{
        char **argv = malloc(10 * sizeof(char *));
        char *token;
        int i = 0;        token = strtok(command, " ");
        while (token != NULL && i < 9)
        {
                argv[i++] = token;
                token = strtok(NULL, " ");
        }
        argv[i] = NULL;        return (argv);
}
