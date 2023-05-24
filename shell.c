#include "main.h"
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
        {
                printf("Shell-> ");
                commandLength = getline(&command, &bufferSize, stdin);
                if (commandLength == -1)
                {
                        printf("Error reading input\n");
                        perror("command");
                        free(command);
                        exit(1);
                }
                command[strlen(command) - 1] = '\0';                if (strcmp(command, "exit") == 0)
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
