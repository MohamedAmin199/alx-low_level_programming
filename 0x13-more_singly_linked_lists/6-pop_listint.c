#include "lists.h"
/**
 * pop_listint - A function that deletes the head node of a listint_t
 * @head: A pointer to the first node.
 * Return: the head node’s data (n) or 0 f the linked list is empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int num;

	if (!head || !*head)
		return (0);

	num = (*head)->n;
	temp = (*head)->next;
	free(*head);
	*head = temp;

	return (num);
}
