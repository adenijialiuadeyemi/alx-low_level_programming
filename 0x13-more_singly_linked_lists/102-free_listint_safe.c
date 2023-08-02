#include "lists.h"

/**
 * free_listint_safe - removing elements of a linked_list
 * @h: Aiming at the 1st node of the list
 *
 * Return: count of elements in the removed_list
 */
size_t free_listint_safe(listint_t **h)
{
size_t ln = 0;
int dif;
listint_t *tmp;

if (!h || !*h)
return (0);

while (*h)
{
dif = *h - (*h)->next;
if (dif > 0)
{
tmp = (*h)->next;
free(*h);
*h = tmp;
ln++;
}
else
{
free(*h);
*h = NULL;
ln++;
break;
}
}

*h = NULL;
return (ln);
}

