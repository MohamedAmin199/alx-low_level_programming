#include "lists.h"
/**
 * get_dnodeint_at_index - A function that returns
 * the nth node of a dlistint_t linked list.
 * @head: The head of the dlistint_t list.
 * @index: The node to locate.
 * Return: Null. if the node does not exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head)
	{
		if (i == index)
			return (head);
		head = head->next;
		i++;
	}
	return (NULL);
}
