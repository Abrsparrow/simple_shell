#include "shell.h"

/**
 * executeCommand - Execute the command using execvp
 * @command: The command to execute
 */

void executeCommand(char *command)
{
	char **argv = parseCommand(command);

	int pid = fork();

	if (pid < 0)
	{
		printf("Fork error\n");
		free(argv);
		exit(1);
	}
	else if (pid == 0)
	{
		/* printf("Executing command: %s\n", command); */
		execvp(argv[0], argv);

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

