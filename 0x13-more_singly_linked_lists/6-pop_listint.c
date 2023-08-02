#include "lists.h"

/**
 * pop_listint - The head_node is deleted
 * @head: aiming at the first element in the linked list
 *
 * Return: the deleted data, otherwise return 0
 */
int pop_listint(listint_t **head)
{
listint_t *tmp;
int num;
if (!head || !*head)
return (0);
num = (*head)->n;
tmp = (*head)->next;
free(*head);
*head = tmp;
return (num);
}

