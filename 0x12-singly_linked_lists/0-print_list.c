#include <stdio.h>
#include "lists.h"

/**
 * print_list - A function to print the elements in a  linked_list
 * @h: to print the value being pointed at
 *
 * Return: return the number of nodes
 */

size_t print_list(const list_t *h)
{
size_t k = 0;

while (h)
{
if (!h->str)
printf("[0] (nil)\n");
else
printf("[%u] %s\n", h->len, h->str);
h = h->next;
k++;
}

return (k);
}

