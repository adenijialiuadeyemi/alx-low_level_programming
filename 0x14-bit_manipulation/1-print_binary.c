#include "main.h"

/**
 * print_binary - prints the binary equivalent of a decimal number
 * @n: number to print in binary
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
			count_i++;
		}
		else if (count_i)
			_putchar('0');
	}
	if (!count_i)
		_putchar('0');
}

