#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void);

/**
 * execute_command - Execute the given command.
 * @command: The command to be executed.
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char *command);

/**
 * main - The main function of the simple shell.
 * Return: Always 0.
 */
int main(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)
	{
		display_prompt();
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if (strlen(input) > 0)
		{
			if (execute_command(input) == -1)
			{
				fprintf(stderr, "Error executing command: %s\n", input);
			}
		}
	}

	return (0);
}
/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt()
{
	printf("#cisfun$ ");
}
/**
 * execute_command - Execute the given command.
 * @command: The command to be executed.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execlp(command, command, NULL);
		perror("Command execution failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			return (0);

		fprintf(stderr, "Error: Command execution failed\n");
		return (-1);
	}
}

