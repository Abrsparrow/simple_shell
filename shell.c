#include "shell.h"
/**
 * main - Simple Shell Program
 *
 * Return: Always 0
 */
int main(void)
{
	const char *print = "#cisfun$ ";
	char *command = NULL;
	size_t bufferSize = 0;
	ssize_t commandLength;

	while (1)
	{
		write(STDOUT_FILENO, print, _strlen(print));
		fflush(stdout);
		commandLength = getline(&command, &bufferSize, stdin);

		if (commandLength == -1)
		{
			perror("No such file or directory\n");
			perror("command");
			free(command);
			exit(1);
		}
		command[_strlen(command) - 1] = '\0';
		if (_strcmp(command, "exit") == 0)
		{
			free(command);
			exit(0);
		}

		executeCommand(command);

			if (!isatty(fileno(stdin)))
			{
				break;
			}
		}
		free(command);
		return (0);
	}
