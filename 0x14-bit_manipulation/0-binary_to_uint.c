#include "main.h"

/**
 * binary_to_uint - to change a base_two number to an unsigned integer
 * @b: the base_two number
 *
 * Return: the unsigned integer after conversion
 */

unsigned int binary_to_uint(const char *b)
{
int n;
unsigned int dec = 0;

if (!b)
return (0);

for (n = 0; b[n]; n++)
{
if (b[n] < '0' || b[n] > '1')
return (0);
dec = 2 * dec + (b[n] - '0');
}

return (dec);
}

