#include "shell.h"
/**
 * executeCommand - Execute the command using execve
 * @command: The command to execute
 */
void executeCommand(char *command)
{
	char **argv = parseCommand(command);

	int pid = fork();

	if (pid < 0)
	{
		perror("Fork error\n");
		free(argv);
		exit(1);
	}
	else if (pid == 0)
	{
		execve(argv[0], argv, environ);

		free(argv);
		perror("./shell");
		exit(EXIT_FAILURE);

	}
	else
	{
		wait(NULL);
	}

	free(argv);
}
