#include "main.h"

/**
 * flip_bits - the number of bits to change
 * from one number to another
 * @n: aiming at 1st_num
 * @m: aiming at 2nd_num
 *
 * Return: count of changed_bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
int k, c = 0;
unsigned long int cur;
unsigned long int excl = n ^ m;

for (k = 63; k >= 0; k--)
{
cur = excl >> k;
if (cur & 1)
c++;
}

return (c);
}

