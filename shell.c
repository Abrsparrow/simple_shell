#include "shell.h"
/**
 * main - Simple Shell Program
 * Return: Always 0
 */
int main(void)
{
	int ret_value, isPiped = !isatty(STDIN_FILENO);
	const char *prompt = isPiped ? "" : "$ ";
	char *command = NULL, *line;
	size_t bufferSize = 0;
	ssize_t commandLength;

	while (1)
	{
		if (!isPiped)
		{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		fflush(stdout);
		}
		commandLength = _getline(&command, &bufferSize, stdin);

		if (commandLength == -1)
		{
			free(command);
			exit(EXIT_SUCCESS);
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
			ret_value = executeCommand(line);
			if (ret_value == -1)
			{
				perror("./shell");
			}
			line = strtok(NULL, "\n");
		}
	}
	free(command);
	return (0);
}
