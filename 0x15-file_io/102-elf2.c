#include "main.h"

/**
 * check_for_elf - To be sure whether a file is ELF.
 * @eid: Aiming to an array containing ELF nums.
 *
 * Description: return 98 when the file isnt ELF.
 */
void check_for_elf(unsigned char *eid)
{
int ind;
for (ind = 0; ind < 4; ind++)
{
if (eid[ind] != 127 &&
eid[ind] != 'E' && eid[ind] != 'L' && eid[ind] != 'F')
{
dprintf(STDERR_FILENO, "This is not an ELF \n");
exit(98);
}
}
}
/**
 * magic_print - Prints ELF_Magic Nums
 * @eid: Aiming at an array containing the maic nums for ELF.
 *
 * Description: Magic_Nums have space seperator.
 */
void magic_print(unsigned char *eid)
{
int ind;
printf("ELF Magic_Nums: ");
for (ind = 0; ind < EI_NIDENT; ind++)
{
printf("%02x", eid[ind]);
if (ind == EI_NIDENT - 1)
	printf("\n");
else
	printf(" ");
}
}
/**
 * print_class - Prints the class of an ELF header.
 * @eid: Aiming at an arr containing the class of ELF.
 */
void print_class(unsigned char *eid)
{
printf("ELF_Class: ");
switch (eid[EI_CLASS])
{
case ELFCLASSNONE:
	printf("none\n");
	break;
case ELFCLASS32:
	printf("ELF32\n");
	break;
case ELFCLASS64:
	printf("ELF64\n");
	break;
default:
	printf("<class_unknown: %x>\n", eid[EI_CLASS]);
}
}
