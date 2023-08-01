#include "lists.h"

/**
 * get_nodeint_at_index -the node of a linked_list at a certain index
 * @head: 1st_node in the linked_list
 * @index: index_ node to be returned
 *
 * Return: pointer to the searched node, otherwise return null
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int k = 0;
listint_t *tmp = head;

while (tmp && k < index)
{
tmp = tmp->next;
k++;
}
return (tmp ? tmp : NULL);
}

