#include <stdio.h>
#include "lists.h"

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - the special nodes are counted
 * in a looped linked_list.
 * @head: aiming at the head of the linked_list.
 *
 * Return: 0 If not looped.
 * Otherwise return the number of special  nodes
 */
size_t looped_listint_len(const listint_t *head)
{
const listint_t *tort, *hare;
size_t nod = 1;
if (head == NULL || head->next == NULL)
return (0);

tort = head->next;
hare = (head->next)->next;

while (hare)
{
if (tort == hare)
{
tort = head;
while (tort != hare)
{
nod++;
tort = tort->next;
hare = hare->next;
}
tort = tort->next;
while (tort != hare)
{
nod++;
tort = tort->next;
}
return (nod);
}
tort = tort->next;
hare = (hare->next)->next;
}
return (0);
}

/**
 * print_listint_safe - Prints the inked_list in a safe way.
 * @head: Aiming at the head of the linked_list.
 *
 * Return: The count of nodes in the linked_list.
 */
size_t print_listint_safe(const listint_t *head)
{
size_t nod, index = 0;
nod = looped_listint_len(head);
if (nod == 0)
{
for (; head != NULL; nod++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
}

else
{
for (index = 0; index < nod; index++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}

printf("-> [%p] %d\n", (void *)head, head->n);
}

return (nod);
}

