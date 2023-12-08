#include "getenv.h"
#include <stdio.h>
#include <string.h>

/**
 * _getenv - Gets the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */

char *_getenv(const char *name)
{
	size_t name_len;

	if (name == NULL || environ == NULL)
		return (NULL);

	name_len = strlen(name);

	for (int i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			return (environ[i] + name_len + 1);
		}
	}

	return (NULL);
}

