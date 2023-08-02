#include "lists.h"

/**
 * delete_nodeint_at_index - At an index, deleting a node in the list
 * @head: pointing to the 1st element in the list
 * @index: node to be delete
 *
 * Return: succes if 1 therwise return fail
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *tmp = *head;
listint_t *cur = NULL;
unsigned int k = 0;
if (*head == NULL)
return (-1);
if (index == 0)
{
*head = (*head)->next;
free(tmp);
return (1);
}
while (k < index - 1)
{
if (!tmp || !(tmp->next))
return (-1);
tmp = tmp->next;
k++;
}
cur = tmp->next;
tmp->next = cur->next;
free(cur);
return (1);
}
