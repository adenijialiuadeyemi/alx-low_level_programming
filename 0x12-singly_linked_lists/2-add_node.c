#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - The beginning of the linked_list is appended by a new nodet
 * @head: the linked_list gets a duplicate pointer
 * @str: adds a new str in the node
 *
 * Return: memory location of the new_element otherwise return a null
 */
list_t *add_node(list_t **head, const char *str)
{
list_t *new;
unsigned int len = 0;

while (str[len])
len++;

new = malloc(sizeof(list_t));
if (!new)
return (NULL);

new->str = strdup(str);
new->len = len;
new->next = (*head);
(*head) = new;

return (*head);
}

