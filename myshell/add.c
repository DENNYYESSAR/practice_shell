#include <stdio.h>

int main(int ac, char **av)
{
    int i = 0;

    while (av[i] != NULL)
    {
        printf("av[%d]: %s\n", i, av[i]);
        i++;
    }

    return (0);
}
