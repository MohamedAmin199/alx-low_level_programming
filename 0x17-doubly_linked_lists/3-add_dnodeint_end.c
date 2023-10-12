#include "lists.h"
/**
 * add_dnodeint_end - A function that adds a new node
 * at the end of a dlistint_t list.
 * @head: A pointer.
 * @n: The integer.
 * Return: the address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new = malloc(sizeof(dlistint_t));

	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (!*head)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	dlistint_t *last = *head;

	while (last->next)
		last = last->next;

	last->next = new;
	new->prev = last;

	return (new);
}
