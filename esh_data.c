#include "shell.h"

/**
 * init_esh - initializes esh_t struct
 * @data: struct address
 * @av: argument av
 */
void init_esh(esh_t *data, char **av)
{
	int i = 0;

	data->esh_name = av[0];
	if (data->arg)
	{
		data->argv = _split_str(data->arg, " \t");
		if (!data->argv)
		{
			data->argv = malloc(sizeof(char *) * 2);
			if (data->argv)
			{
				data->argv[0] = _strdup(data->arg);
				data->argv[1] = NULL;
			}
		}
		for (i = 0; data->argv && data->argv[i]; i++)
			;

		replace_vars(data);
	}
}
