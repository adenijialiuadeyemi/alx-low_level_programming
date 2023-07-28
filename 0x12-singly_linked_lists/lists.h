#ifndef LISTS_H
#define LISTS_H

/**
 * Description: Holberton project on Singly Linked List
 * struct char_arr - singly linked list
 * @str: string - (malloc string)
 * @len: to determine how long a string is
 * @next: this points to the next node
 */

typedef struct char_arr
{
	char *str;
	unsigned int len;
	struct char_arr *next;
} t_arr;

size_t print_list(const t_arr *h);
size_t list_len(const t_arr *h);
list_t *add_node(t_arr **head, const char *str);
list_t *add_node_end(t_arr **head, const char *str);
void free_list(t_arr *head);
#endif

