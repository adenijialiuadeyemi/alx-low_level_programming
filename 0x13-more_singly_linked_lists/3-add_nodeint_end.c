#include "lists.h"

/**
 * add_nodeint_end - A node is added at the end of a linked_list
 * @head: aiming at the first element of the linked_list
 * @n: entering data into the new_node
 *
 * Return: ptr to a new_node,otherwise return NULL
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node;
listint_t *tmp = *head;
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);
new_node->n = n;
new_node->next = NULL;
if (*head == NULL)
{
*head = new_node;
return (new_node);
}
while (tmp->next)
tmp = tmp->next;
tmp->next = new_node;
return (new_node);
}
