#include "lists.h"

/**
 * print_list - A function that prints all the elements of a list_t list.
 * @h: pointer to the list_t list.
 * Return: The number of nodes.
 */
size_t print_list(const list_t *h)
{
	if (h == NULL)
		return (0);

	if (h->str == NULL)
		printf("[0] (nil)\n");
	else
		printf("[%d] %s\n", h->len, h->str);

	return (1 + print_list(h->next));
}
