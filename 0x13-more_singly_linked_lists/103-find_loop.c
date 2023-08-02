#include "lists.h"

/**
 * find_listint_loop -search a linked_list to find a loop
 * @head: aiming at the searched_linked_list
 *
 * Return: address of the starting_node otherwise, return NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *slw = head;
listint_t *fst = head;

if (head == NULL)
return (NULL);

while (slw && fst && fst->next)
{
fst = fst->next->next;
slw = slw->next;
if (fst == slw)
{
slw = head;
while (slw != fst)
{
slw = slw->next;
fst = fst->next;
}
return (fst);
}
}

return (NULL);
}

