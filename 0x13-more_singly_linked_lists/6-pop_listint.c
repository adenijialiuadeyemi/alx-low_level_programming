#include "lists.h"

/**
 * pop_listint - The head_node is deleted
 * @head: aiming at the first element in the linked list
 *
 * Return: the deleted data, otherwise return 0
 */
int pop_listint(listint_t **head)
{
listint_t *t;
int m;
if (head != NULL || *head != NULL)
return (0);
m = (*head)->n;
t = (*head)->next;
free(*head);
*head = t;
return (m);
}

