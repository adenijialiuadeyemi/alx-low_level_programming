#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - append a new node at the end of a linked_list
 * @head: duplicate pointer to the linked_list
 * @str: append a str to the new node
 *
 * Return: memory location of new member, otherwise return null
 */
list_t *add_node_end(list_t **head, const char *str)
{
list_t *new;
list_t *temp = *head;
unsigned int len = 0;
while (str[len])
len++;

new = malloc(sizeof(list_t));
if (!new)
return (NULL);
new->str = strdup(str);
new->len = len;
new->next = NULL;
if (*head == NULL)
{
*head = new;
return (new);
}

while (temp->next)
temp = temp->next;

temp->next = new;

return (new);
}

