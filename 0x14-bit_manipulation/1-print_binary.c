#include "main.h"

/**
 * print_binary - convert base_10 number to base_2
 * @n: the base_2 number
 */

void print_binary(unsigned long int n)
{
int k, c = 0;
unsigned long int cur;

for (k = 63; k >= 0; k--)
{
cur = n >> k;
if (cur & 1)
{
_putchar('1');
c++;
}
else if (c)
_putchar('0');
}
if (!c)
_putchar('0');
}

