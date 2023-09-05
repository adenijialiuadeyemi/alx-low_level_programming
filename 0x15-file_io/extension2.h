/**
 * elf_chk - The function checks ELF file.
 * @elf_id: Aiming at the array of ELF file
 *
 * Description: 98 when not an ELF file
 */
void elf_chk(unsigned char *elf_id)
{
        int idx;

        for (idx = 0; idx < 4; idx++)
        {
                if (elf_id[idx] != 127 &&
                                elf_id[idx] != 'E' &&
                                elf_id[idx] != 'L' &&
                                elf_id[idx] != 'F')
                {
                        dprintf(STDERR_FILENO, "Error: ELF file Error\n");
                        exit(98);
                }
        }
}
/**
 * print_magic - Printing the ELF Magic Num
 * @elf_id: Aiming at the array of ELF file
 *
 * Description: Magic num with space separator
 */
void print_magic(unsigned char *elf_id)
{
        int idx;

        printf("  Magic:   ");

        for (idx = 0; idx < EI_NIDENT; idx++)
        {
                printf("%02x", elf_id[idx]);

                if (idx == EI_NIDENT - 1)
                        printf("\n");
                else
                        printf(" ");
        }
}
