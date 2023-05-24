#include "shell.h"
/**
 * main - Simple Shell Program
 * Return: Always 0
 */
int main(void)
{
	const char *print = "#cisfun$ ";
	char *command = NULL;
	size_t bufferSize = 0;
	ssize_t commandLength;
	char *line;

	while (1)
	{
		write(STDOUT_FILENO, print, _strlen(print));
		fflush(stdout);
		commandLength = getline(&command, &bufferSize, stdin);

		if (commandLength == -1)
		{
			perror("getline");
			free(command);
			exit(EXIT_FAILURE);
		}
		command[_strlen(command) - 1] = '\0';
		if (_strcmp(command, "exit") == 0)
		{
			free(command);
			exit(0);
		}
		line = strtok(command, "\n");

		while (line != NULL)
		{
			executeCommand(line);
			line = strtok(NULL, "\n");
			}
		}

		free(command);
		return (0);
	}
