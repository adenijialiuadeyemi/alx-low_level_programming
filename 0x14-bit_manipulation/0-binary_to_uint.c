#include "main.h"

/**
 * binary_to_uint - This function converts Binary_To_Unsigned Integer
 * @b: The Binary_Number String
 *
 * Return: The Unsined integer
 */
unsigned int binary_to_uint(const char *b)
{
int count_i;
unsigned int num_dec = 0;
if (!b)
	return (0);
for (count_i = 0; b[count_i]; count_i++)
{
if (b[count_i] > '1' || b[count_i] < '0')
	return (0);
num_dec = 2 * num_dec + (b[count_i] - '0');
}
return (num_dec);
}
