#include "shell.h"

int is_executable(char *path);
/**
 * find_path - finds command in the PATH env
 * @path_str: string PATH
 * @command: the command
 * Return: path of command or NULL
 */
char *find_path(char *path_str, char *command)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!path_str)
		return (NULL);
	if ((_strlen(command) > 2) && starts_with(command, "./"))
		if (is_executable(command))
			return (command);
	while (1)
	{
		if (!path_str[i] || path_str[i] == ':')
		{
			path = dup_chars(path_str, curr_pos, i);
			if (!*path)
				_strcat(path, command);
			else
			{
				_strcat(path, "/");
				_strcat(path, command);
			}
			if (is_executable(path))
				return (path);
			if (!path_str[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
