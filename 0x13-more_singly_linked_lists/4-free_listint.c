#include "lists.h"

/**
 * free_listint - removing the linked_list content
 * @head: removing the content of listint_t
 */
void free_listint(listint_t *head)
{
listint_t *tmp;
while (head != NULL)
{
tmp = head->next;
free(head);
head = tmp;
}
}

