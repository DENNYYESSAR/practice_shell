#include <stdio.h>

/**
 * main - Entry point of the program
 * @ac: Number of arguments
 * @av: Array of argument strings
 *
 * Return: Always 0 (Success)
 */
int main(int ac, char **av)
{
	int i;

	printf("Number of arguments: %d\n", ac);

	printf("Argument vector:\n");
	for (i = 0; i < ac; i++)
	{
		printf("av[%d]: %s\n", i, av[i]);
	}

	return (0);
}

