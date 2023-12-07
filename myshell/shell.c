#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

/**
 * executeCommand - Executes the given command in a child process.
 * @command: The command to be executed.
 */
void executeCommand(const char *command)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) /* Child process */
    {
        execlp(command, command, (char *)NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    else /* Parent process */
    {
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
        {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        }
        else
        {
            fprintf(stderr, "Child process did not exit normally\n");
        }
    }
}

/**
 * main - Simple shell that runs commands with their full path.
 *
 * Return: Always 0.
 */
int main(void)
{
    char command[MAX_COMMAND_LENGTH];

    while (1)
    {
        printf("simple_shell> ");

        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            break; /* Exit if end-of-file (Ctrl+D) is encountered */
        }

        char *newline = strchr(command, '\n');
        if (newline != NULL)
        {
            *newline = '\0';
        }

        executeCommand(command);
    }

    printf("Exiting shell.\n");

    return (0);
}

