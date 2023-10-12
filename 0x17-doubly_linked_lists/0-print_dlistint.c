#include "lists.h"
/**
 * print_dlistint - A function that prints the elements of a dlistint_t list.
 * @h: The address of head node.
 * Return: the number of nodes.
 */
size_t print_dlistint(const dlistint_t *h);
{
	size_t i = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}
