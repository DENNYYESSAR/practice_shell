#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of the program
 * Return: Always 0 (success)
 */
int main(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ ");
	fflush(stdout);

	read = getline(&command, &len, stdin);

	if (read == -1)
	{
		perror("getline");
		return 1;
	}

	printf("%s", command);

	free(command);

	return (0);
}
