#include "main.h"

/**
 * clear_bit - This function clears the bit value by setting it to 0
 * @n: aiming at the number to change
 * @index: clear bit index
 *
 * Return: -1 when failed, 1 when successful
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}

