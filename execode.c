#include "shell.h"
/**
 * executeCommand - Execute the command using execve
 * @command: The command to execute
 */
void executeCommand(char *command)
{
	int pid = fork();

    if (pid < 0)
    {
        perror("Fork error\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        char *args[2] = {command, NULL};
        char *path = getenv("PATH");
        char *token;
        char *pathCommand;
        int execResult;

        if (path == NULL)
        {
            perror("Unable to get PATH\n");
            exit(EXIT_FAILURE);
        }

        token = strtok(path, ":");
        while (token != NULL)
        {
            pathCommand = malloc(strlen(token) + strlen(command) + 2);
            if (pathCommand == NULL)
            {
                perror("Malloc error\n");
                exit(EXIT_FAILURE);
            }
            _strcpy(pathCommand, token);
            strcat(pathCommand, "/");
            strcat(pathCommand, command);

            execResult = execve(pathCommand, args, environ);
            free(pathCommand);

            if (execResult != -1)
            {
                break;
            }

            token = strtok(NULL, ":");
        }

        perror(command);
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }
}
