#include "lists.h"

/**
 * listint_len - size of a linked_list
 * @h: run through the linked_list
 *
 * Return: count of the nodes present
 */
size_t listint_len(const listint_t *h)
{
size_t i = 0;

while (h)
{
i++;
h = h->next;
}
return (i);
}
