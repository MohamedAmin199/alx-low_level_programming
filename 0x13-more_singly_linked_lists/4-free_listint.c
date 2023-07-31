#include "lists.h"
/**
 * free_listint - A function that frees a listint_t list.
 * @head: A pointer to the first node.
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
