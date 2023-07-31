#include "lists.h"
/**
 * sum_listint - calculates the sum of all the data in a listint_t list.
 * @head: A pointer to the first node.
 * Return: the sum of all the data (n) or 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
