#include "lists.h"

/**
 * sum_listint - the sum of all element of the linked list is to be calculated
 * @head: aiming at the first node
 *
 * Return: final addition
 */
int sum_listint(listint_t *head)
{
int t = 0;
listint_t *tmp = head;

while (tmp != NULL)
{
t += tmp->n;
tmp = tmp->next;
}

return (t);
}

