#include "shell.h"

/**
 * read_input_buffer - buffers of commands
 * @data: parameter
 * @buf: address of buffer
 * @len: address of len
 *
 * Return: readden bytes
 */
ssize_t read_input_buffer(esh_t *data, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);

		r = getline(buf, &len_p, stdin);

		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}
			data->flag = 1;
			remove_comments(*buf);
			*len = r;
			data->buffer = buf;
		}
	}
	return (r);
}

