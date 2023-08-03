#include "main.h"

/**
 * clear_bit - removing the the bit_val by setting it to 0
 * @n: aiming at the number to change
 * @index: bit_index to be wiped off
 *
 * Return: 1 if no error occur, otherwise return -1
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
if (index > 63)
return (-1);

*n = (~(1UL << index) & *n);
return (1);

}

