#include "lists.h"

/**
 * add_nodeint - A new node is added at the beginning of a linked_list
 * @head: the first node is pointed at
 * @n: adding data into the new node
 *
 * Return: ptr to the new_node, otherwise return NULL
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_node;

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
	return (NULL);

new_node->n = n;
new_node->next = *head;
*head = new_node;
return (new_node);
}

