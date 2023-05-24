#include "shell.h"
/**
 * main - Simple Shell Program
 *
 * Return: Always 0
 */
int main(void)
{
	char *command = NULL;
	size_t bufferSize = 0;
	ssize_t commandLength;

	while (1)
<<<<<<< HEAD
	{
		printf("cisfun");
		commandLength = getline(&command, &bufferSize, stdin);
		if (commandLength == -1)
		{
			printf("Error reading input\n");
			perror("command");
			free(command);
			exit(1);
		}
		command[strlen(command) - 1] = '\0';
		if (strcmp(command, "exit") == 0)
		{
			free(command);
			exit(0);
		}
		executeCommand(command);
=======
        {
                printf("#cisfun$ ");
                commandLength = getline(&command, &bufferSize, stdin);
                if (commandLength == -1)
                {
                        printf("Error reading input\n");
                        perror("command");
                        free(command);
                        exit(1);
                }
                command[strlen(command) - 1] = '\0';

                if (strcmp(command, "exit") == 0)
                {
                        free(command);
                        exit(0);
                }
	
	executeCommand(command);
>>>>>>> 605dfacefb2b09afc7cb8c28399f47cbcc9b843e

		if (!isatty(fileno(stdin)))
		{
			break;
		}
	}
	free(command);
	return (0);
}
