#include "shell.h"
/**
 * executeCommand - Execute the command using execve
 * @command: The command to execute
 */
void executeCommand(char *command)
{
	char **args = malloc(2 * sizeof(char *));
	char *envp[] = {NULL};
	int pid = fork();

	if (args == NULL)
	{
		perror("Memory allocation error");
		exit(1);
	}

	args[0] = command;
	args[1] = NULL;

	if (pid < 0)
	{
		perror("Fork error\n");
		exit(1);
	}
	else if (pid == 0)
	{

		execve(command, args, envp);
		perror("./shell");
		exit(EXIT_FAILURE);

	}
	else
	{
		free(args);
		wait(NULL);
	}
}
