#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * splitString - Splits a string into an array of words using strtok.
 * @inputString: The input string to be split.
 * @delimiter: The delimiter used to split the string.
 * @count: Pointer to store the number of words.
 *
 * Return: An array of words.
 */
char **splitString(const char *inputString, const char *delimiter, int *count)
{
	char *tempString = strdup(inputString);
	char *token = strtok(tempString, delimiter);
	int numWords = 0;

	while (token != NULL)
	{
		numWords++;
		token = strtok(NULL, delimiter);
	}

	char **wordsArray = (char **)malloc(numWords * sizeof(char *));

	strcpy(tempString, inputString);
	token = strtok(tempString, delimiter);

	for (int i = 0; i < numWords; i++)
	{
		wordsArray[i] = strdup(token);
		token = strtok(NULL, delimiter);
	}

	*count = numWords;
	free(tempString);

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

