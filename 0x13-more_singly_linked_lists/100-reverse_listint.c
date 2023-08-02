#include "lists.h"

/**
 * reverse_listint - the linked_list is reversed
 * @head: aiming at the first node in the list
 *
 * Return: aiming at the 1st nodei in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
listint_t *prv = NULL;
listint_t *next = NULL;

while (*head)
{
next = (*head)->next;
(*head)->next = prv;
prv = *head;
*head = next;
}

*head = prv;

return (*head);
}

