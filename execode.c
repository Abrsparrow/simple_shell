#include "shell.h"
/**
 * executeCommand - Execute the command using execve
 * @command: The command to execute
 */
void executeCommand(char *command)
{
	char **argv = parseCommand(command);
	extern char **environ;

	int pid = fork();

	if (pid < 0)
	{
		printf("Fork error\n");
		free(argv);
		exit(1);
	}
	else if (pid == 0)
	{
		execve(argv[0], argv, environ);

		perror("Error executing command");
		free(argv);
		exit(1);
	}
	else
	{
		wait(NULL);
	}

	free(argv);
}

