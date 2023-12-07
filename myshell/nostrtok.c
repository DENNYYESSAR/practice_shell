#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * splitString - Splits a string into an array of words without using strtok.
 * @inputString: The input string to be split.
 * @delimiter: The delimiter used to split the string.
 * @count: Pointer to store the number of words.
 *
 * Return: An array of words.
 */
char **splitString(const char *inputString, const char *delimiter, int *count)
{
	char *tempString = strdup(inputString);

	int numWords = 1;

	for (int i = 0; tempString[i] != '\0'; i++)
	{
		if (tempString[i] == delimiter[0])
		{
			numWords++;
		}
	}

	char **wordsArray = (char **)malloc(numWords * sizeof(char *));

	if (wordsArray == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	int i = 0;
	char *start = tempString;

	while (*tempString != '\0')
	{
		if (*tempString == delimiter[0])
		{
			*tempString = '\0';
			wordsArray[i++] = strdup(start);
			start = tempString + 1;
		}
		tempString++;
	}
	wordsArray[i++] = strdup(start);

	*count = numWords;

	free(strdup(inputString));

	return (wordsArray);
}

/**
 * main - Entry point of the program.
 *
 * Return: 0 on success.
 */
int main(void)
{
	const char *input = "This is a sample string";
	const char *delimiter = " ";

	int count;
	char **words = splitString(input, delimiter, &count);

	printf("Number of words: %d\n", count);
	for (int i = 0; i < count; i++)
	{
		printf("%s\n", words[i]);
		free(words[i]);
	}

	free(words);

	return (0);
}

