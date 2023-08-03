#include "main.h"

/**
 * get_bit - give back the bit_value at a specific index of decimal number
 * @n: searched_number
 * @index: bit index
 *
 * Return: bit value
 */

int get_bit(unsigned long int n, unsigned int index)
{
int val_bit;

if (index > 63)
return (-1);

val_bit = (n >> index) & 1;

return (val_bit);
}

