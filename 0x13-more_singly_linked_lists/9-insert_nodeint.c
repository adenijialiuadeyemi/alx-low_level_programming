#include "lists.h"

/**
 * insert_nodeint_at_index - add a new node in a linked_list,
 * at a specific position
 * @head: the 1st node in the linked_list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int k;
listint_t *new_node;
listint_t *tmp = *head;

new_node = malloc(sizeof(listint_t));
if (!new_node || !head)
return (NULL);

new_node->n = n;
new_node->next = NULL;

if (idx == 0)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}
for (k = 0; tmp && k < idx; k++)
{
if (k == idx - 1)
{
new_node->next = tmp->next;
tmp->next = new_node;
return (new_node);
}
else
tmp = tmp->next;
}

return (NULL);
}

