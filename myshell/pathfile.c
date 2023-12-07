#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PATH_SEPARATOR ":"


/**
 * findExecutable - Searches for an executable file in the specified path.
 * @filename: The name of the file to search for.
 * @path: The PATH environment variable.
 *
 * Description:
 * This function searches for the specified file in each directory
 * listed in the PATH environment variable. If found, it prints
 * the full path of the executable file.
 */
void findExecutable(const char *filename, const char *path)
{
	char *token, *pathCopy;
	size_t filenameLen = strlen(filename);

	/* Make a copy of the PATH to avoid modifying the original */
	pathCopy = strdup(path);
	if (pathCopy == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	/* Tokenize the PATH using the PATH_SEPARATOR (colon) */
	token = strtok(pathCopy, PATH_SEPARATOR);

	/* Iterate through each directory in PATH */
	while (token != NULL)
	{
		/* Create a buffer for the full path of the file */
		char fullPath[256]; /* Adjust the size as needed */

		/* Construct the full path by appending the filename to the directory */
		snprintf(fullPath, sizeof(fullPath), "%s/%s", token, filename);

		/* Check if the file is executable */
		if (access(fullPath, X_OK) == 0)
		{
			printf("%s\n", fullPath);
			free(pathCopy);
			return; /* Exit after finding the first match */
		}

		/* Move to the next directory in PATH */
		token = strtok(NULL, PATH_SEPARATOR);
	}

	/* File not found in PATH */
	printf("%s not found in PATH\n", filename);

	free(pathCopy);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 1 on failure.
 *
 * Description:
 * The main function takes command-line arguments representing
 * filenames and searches for each file in the directories listed
 * in the PATH environment variable.
 */
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* Get the value of the PATH environment variable */
	const char *path = getenv("PATH");

	if (path == NULL)
	{
		fprintf(stderr, "PATH environment variable not set\n");
		exit(EXIT_FAILURE);
	}

	/* Iterate through each filename provided as a command-line argument */
	for (int i = 1; i < argc; i++)
	{
		findExecutable(argv[i], path);
	}

	return (0);
}

