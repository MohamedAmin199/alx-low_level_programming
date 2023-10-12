#include "lists.h"
/**
 * dlistint_len - A function that returns the num of elements in a linked list.
 * @h: The address of head node.
 * Return: The number of elements in the dlistint_t list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}
