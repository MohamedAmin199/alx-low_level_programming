#include "lists.h"
/**
 * print_listint_safe - A function that prints a listint_t linked list.
 * @head: A pointer to the first node.
 * Return: the number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tmp_n = head;
	size_t counter = 0;
	int visited_node = 0;
	const listint_t *visited_nodes[1024]; /* assuming a maximum of 1024 nodes */

	while (tmp_n)
	{
		printf("[%p] %d\n", (void *)tmp_n, tmp_n->n);
		counter++;

		/* Check if the current node has been visited before */
		for (int i = 0; i < visited_node; i++)
		{
			if (tmp_n == visited_nodes[i])
			{
				printf("-> [%p] %d\n", (void *)tmp_n, tmp_n->n);
				return (counter);
			}
		}
		/* Mark the current node as visited */
		visited_nodes[visited_node++] = tmp_n;

		tmp_n = tmp_n->next;
	}
	return (counter);
}
