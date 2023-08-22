#include "shell.h"

/**
 * free_strings - frees a string
 * @pp: string of strings
 */
void free_strings(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}
