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

	
	executeCommand(command);

		if (!isatty(fileno(stdin)))
		{
			break;
		}
	}

	free(command);
	return (0);
}
