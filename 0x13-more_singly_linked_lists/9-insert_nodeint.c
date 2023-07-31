#include "lists.h"
/**
 * insert_nodeint_at_index - A function that inserts a new node
 * at a given position.
 * @head: A pointer to the first node.
 * @idx: The index of the listint_t list.
 * @n: The integer.
 * Returns: the address of the new node, or NULL if it failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	listint_t *current = *head;
	unsigned int node = 0;

	while (current != NULL && node < (idx - 1))
	{
		current = current->next;
		node++;
	}
	if (current == NULL)
	{
		free(new);
		return (NULL);
	}

	new->next = current->next;
	current->next = new;

	return (new);
}
