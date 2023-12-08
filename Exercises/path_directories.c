#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_path_directories - Prints each directory
 * in the PATH environment variable.
 */
void print_path_directories(void)
{
	char *path_variable = getenv("PATH");

	if (path_variable == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found.\n");
		return;
	}

	char path_copy[strlen(path_variable) + 1];

	strcpy(path_copy, path_variable);

	char *token = strtok(path_copy, ":");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
}
/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	print_path_directories();
	return (0);
}

