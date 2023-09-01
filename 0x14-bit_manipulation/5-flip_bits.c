#include "main.h"

/**
 * flip_bits - This function flip bits
 * @n: num_first
 * @m: num_second
 *
 * Return: num of flipped_bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int count_i, count = 0;
	unsigned long int present;
	unsigned long int excl = n ^ m;

	for (count_i = 63; count_i >= 0; count_i--)
	{
		present = excl >> count_i;
		if (present & 1)
			count++;
	}

	return (count);
}

