#include <stdlib.h>
#include "lists.h"

/**
 * list_len - length of members in a linked_list
 * @h: pointing to a member in the list list_t
 *
 * Return: the count of members present in h
 */
size_t list_len(const list_t *h)
{
size_t z = 0;
while (h)
{
z++;
h = h->next;
}
return (z);
}

