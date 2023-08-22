#include "shell.h"

/**
 * _atoi - converts string to integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string or -1 on error or converted number
 */
int _atoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - print error message
 * @data: parameter and return info struct
 * @estr: string contain error type
 * Return: 0 if no numbers in string or -1 on error or converted number
 */
void print_error(esh_t *data, char *estr)
{
	_puts(data->esh_name);
	_puts(": ");
	print_decimal(data->line_count);
	_puts(": ");
	_puts(data->argv[0]);
	_puts(": ");
	_puts(estr);
}
