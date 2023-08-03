#include "main.h"

/**
 * get_endianness - checking to get  endianness
 * Return: 0 if it is a big endiann, otherwise return 1
 */
int get_endianness(void)
{
unsigned int k = 1;
char *c = (char *) &k;

return (*c);
}

