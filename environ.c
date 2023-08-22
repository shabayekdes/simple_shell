#include "shell.h"

/**
 * esh_env - prints current environment
 * @data: Structure containing potential arguments.
 * Return: 0
 */
int esh_env(esh_t *data)
{
	var_t *h = data->env;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
	}

	return (0);
}
