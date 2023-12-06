#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (success)
 */
int main(void)
{
    pid_t current_pid = getpid();
    printf("Current PID: %d\n", current_pid);

    pid_t parent_pid = getppid();
    printf("Parent PID: %d\n", parent_pid);

    return (0);
}
