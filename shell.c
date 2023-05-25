#include "shell.h"
/**
 * main - Simple Shell Program
 * Return: Always 0
 */
int main(void)
{
	int isPiped = !isatty(STDIN_FILENO);
	const char *prompt = isPiped ? "" : "$ ";
	char *command = NULL;
	size_t bufferSize = 0;
	ssize_t commandLength;
	char *line;

	while (1)
	{
		if (!isPiped)
		{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		fflush(stdout);
		}
		commandLength = getline(&command, &bufferSize, stdin);

		if (commandLength == -1)
		{
			/* perror("./shell: No such file or directory"); */
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
