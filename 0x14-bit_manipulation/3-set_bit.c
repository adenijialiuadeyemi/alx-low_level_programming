#include "main.h"

/**
 * set_bit - The func sets a bit to 1
 * @n: aiming at the number to be changed
 * @index: bit index
 *
 * Return: -1 when failed, 1 when successful
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}

