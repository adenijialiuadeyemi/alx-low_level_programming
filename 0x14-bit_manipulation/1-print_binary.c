#include "main.h"

/**
 * print_binary - The func generates the bin_equivalent of a dec_num
 * @n: Number to be printed in binary
 */
void print_binary(unsigned long int n)
{
	int count_i, count = 0;
	unsigned long int present;

	for (count_i = 63; count_i >= 0; count_i--)
	{
		present = n >> count_i;

		if (present & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}

