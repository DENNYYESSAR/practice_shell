#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - Creates 5 child processes, each executing "ls -l /tmp".
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t pid;
	int status;

	for (int i = 0; i < 5; i++)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			printf("Child %d executing ls -l /tmp\n", i + 1);
			execlp("ls", "ls", "-l", "/tmp", (char *)NULL);
			perror("execlp");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);

			if (WIFEXITED(status))
			{
				printf("Child %d exited with status %d\n", i + 1, WEXITSTATUS(status));
			}
			else
			{
				fprintf(stderr, "Child %d did not exit normally\n", i + 1);
			}
		}
	}

	return (0);
}

