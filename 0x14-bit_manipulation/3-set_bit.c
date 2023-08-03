#include "main.h"

/**
 * set_bit - sets a bit_index to 1
 * @n: aiming at the num to change
 * @index: bit_index to set to 1
 *
 * Return: 1 if no error, otherwise return -1
 */

int set_bit(unsigned long int *n, unsigned int index)
{
if (index > 63)
return (-1);

*n = ((1UL << index) | *n);
return (1);
}

