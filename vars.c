#include "shell.h"

int replace_string(char **old, char *new);
/**
 * detect_chain_delimiter - test if current char in buffer is a chain delimeter
 * @data: parameter struct
 * @buf: char buffer
 * @p: address of current position in buf
 * Return: 1 if chain delimeter or 0
 */
int detect_chain_delimiter(esh_t *data, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		data->buffer_type = 1;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		data->buffer_type = 2;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		data->buffer_type = 3;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * handle_chain - checks if continue chaining based on last status
 * @data: parameter struct
 * @buf: char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 * Return: Void
 */
void handle_chain(esh_t *data, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (data->buffer_type == 2)
	{
		if (data->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (data->buffer_type == 1)
	{
		if (!data->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

