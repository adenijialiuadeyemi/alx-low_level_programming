#include "lists.h"

/**
 * print_listint - This displays all element s in a linked_list
 * @h: to print a linked list of type listint_t
 *
 * Return: number of available nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t j = 0;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		j++;
		h = h->next;
	}
	return (j);
}

