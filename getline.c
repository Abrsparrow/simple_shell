#include "shell.h"
/**
 * _getline - Reads character from a stream.
 * @lineptr: A Buffer to store the characterCount.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 * Return: The number of bytes read.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t bytes_read;
	int read_result;
	char *inputBuffer, currentChar = 'x';
	static ssize_t characterCount;

	if (characterCount == 0)
		fflush(stream);
	else
		return (-1);
	characterCount = 0;
	inputBuffer = malloc(sizeof(char) * 120);
	if (!inputBuffer)
		return (-1);
	while (currentChar != '\n')
	{
		read_result = read(STDIN_FILENO, &currentChar, 1);
		if (read_result == -1 || (characterCount  == 0 && read_result == 0))
		{
			free(inputBuffer);
			return (-1);
		}
		if (characterCount != 0  &&  read_result == 0)
		{
			characterCount++;
			break;
		}
		if (characterCount >= 120)
			inputBuffer = realloc(inputBuffer, characterCount + 1);

		inputBuffer[characterCount] = currentChar;
		characterCount++;
	}
}
