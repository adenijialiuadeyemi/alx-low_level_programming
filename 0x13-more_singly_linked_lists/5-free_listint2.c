#include "lists.h"

/**
 * free_listint2 - removing the elements of a linked_list
 * @head: aiming at the linked_list to be freed
 */
void free_listint2(listint_t **head)
{
listint_t *tmp;
if (head == NULL)
return;
while (*head)
{
tmp = (*head)->next;
free(*head);
*head = tmp;
}
*head = NULL;
}

