#include "shell.h"
#include <stdbool.h>
/**
 * executeCommand- Execute the command using execve
 * @command: The command to execute
 * Return: Return 1 in case of any error
 */
int executeCommand(char *command)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("Fork error\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char **args = malloc(4 * sizeof(char *));

		if (args == NULL)
		{
			perror("Memory allocation error\n");
			exit(EXIT_FAILURE);
		}
		args[0] = "/bin/sh";
		args[1] = "-c";
		args[2] = malloc(strlen(command) + 1);
		strcpy(args[2], command);
		args[3] = NULL;
		/* char *envp[] = {NULL}; */
		execve(args[0], args, environ);
		perror(args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		wait(&status);
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);

			return ((exit_status == 0) ? 0 : 1);
		}
	}
	return (1);
}
