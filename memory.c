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
/**
 * safely_free_pointer - Frees memory allocated for a pointer
 * @ptr: address of pointer to be free
 *
 * Return: 1 if freed, or 0.
 */
int safely_free_pointer(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
