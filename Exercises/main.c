#include "getenv.h"
#include <stdio.h>

int main(void)
{
    /* Example of using _getenv */
    char *path_value = _getenv("PATH");

    if (path_value != NULL)
    {
        printf("Value of PATH: %s\n", path_value);
    }
    else
    {
        printf("PATH not found in environment variables.\n");
    }

    return (0);
}
