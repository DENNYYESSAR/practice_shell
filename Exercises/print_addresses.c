#include <stdio.h>

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * @envp: Array of environment variable strings
 *
 * Description: Prints the address of env (the third parameter of the main
 * function) and environ (the global variable).
 *
 * Return: Always 0 (Success)
 */
int main(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[], char *envp[])
{
	extern char **environ;

	printf("Address of env (envp): %p\n", (void *)envp);

	printf("Address of environ: %p\n", (void *)environ);

	return (0);
}

