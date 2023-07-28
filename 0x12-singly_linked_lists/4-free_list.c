#include <stdlib.h>
#include "lists.h"

/**
 * free_list - removing a linked_list
 * @head: removing members of a linked_list
 */
void free_list(list_t *head)
{
list_t *temp;
while (head)
{
temp = head->next;
free(head->str);
free(head);
head = temp;
}
}

