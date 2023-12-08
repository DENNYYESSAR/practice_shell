#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the environment variables
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	extern char **environ;

	int i;
	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}

	return (0);
}

