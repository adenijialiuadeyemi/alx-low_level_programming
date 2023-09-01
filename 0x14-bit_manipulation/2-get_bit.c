#include "main.h"

/**
 * get_bit - This function gets the bit value
 * @n: searched_number
 * @index: Bit_Index
 *
 * Return: Bit_value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit;

	if (index > 63)
		return (-1);

	bit = (n >> index) & 1;

	return (bit);
}

