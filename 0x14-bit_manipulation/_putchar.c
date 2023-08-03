#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @k: char k  is to be printed
 *
 * Return: 1 when the program runs without error.
 * Otherwise return -1 and set error_no
 */
int _putchar(char k)
{
return (write(1, &k, 1));
}

