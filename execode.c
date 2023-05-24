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
		exit(1);
	}
	else if (pid == 0)
	{
		char *args[4];
		char *envp[] = {NULL};

		args[0] = "/bin/sh";
		args[1] = "-c";
		args[2] = command;
		args[3] = NULL;

		execve("/bin/sh", args, envp);
		perror("/bin/sh");
		exit(EXIT_FAILURE);


	}
	else
	{
		free(args);
		wait(NULL);
	}
}
