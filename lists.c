#include "shell.h"

/**
 * add_node_end - adds a node to end of list
 * @head: address head node
 * @str: str of  node
 * @num: node index for  history
 *
 * Return: list size
 */
var_t *add_node_end(var_t **head, const char *str, int num)
{
	unsigned int i;
	char *s;
	var_t *new_node, *node;
	unsigned int n = sizeof(var_t);

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(var_t));
	if (!new_node)
		return (NULL);

	s = (void *)new_node;
	for (i = 0; i < n; i++)
		s[i] = 0;

	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{

		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}
