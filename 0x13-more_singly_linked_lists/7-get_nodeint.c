#include "lists.h"
/**
 * get_nodeint_at_index - A function that returns the nth node.
 * @head: A pointer to the first node.
 * @index: The index of the node.
 * Return: NULL if the node does not exist
 * Otherwise -  pointer to the node.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int node = 0;

	while (node < index)
	{
		if (head == NULL)
			return (NULL);

		head = head->next;
		node++;
	}
	return (head);
}
