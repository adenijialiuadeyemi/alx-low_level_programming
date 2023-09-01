#ifndef MAIN_H
#define MAIN_H

/* prototype for task 0 */
unsigned int binary_to_uint(const char *b);

/* prototype for task 1 */
void print_binary(unsigned long int n);

/* prototype for getting bit */
int get_bit(unsigned long int n, unsigned int index);

/* prototype for setting bit */
int set_bit(unsigned long int *n, unsigned int index);

/* prototype for clearing bit */
int clear_bit(unsigned long int *n, unsigned int index);

/* prototype for flipping bits */
unsigned int flip_bits(unsigned long int n, unsigned long int m);

/* prototype for _atoi */
int _atoi(const char *s);

/* prototype to get endianness */
int get_endianness(void);

/* prototype for _putchar */
int _putchar(char c);

#endif
