#include "main.h"
#include "101-elf2.c"
#include "102-elf2.c"

/**
 * entry_print - Prints the entry point of an ELF header.
 * @e_entry: The mem_location of the ELF_entry_point.
 * @e_ident: Aiming at an array containing the ELF class.
 */
void entry_print(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: Aiming at the ELF_file.
 *
 * Description: If the file cant close return 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - shows the detail presesent in
 * ELF_header at the beginning of an ELF file.
 * @argc: count of args passed to the set of instructions.
 * @argv: An array of ptrs to the args.
 *
 * Return: 0 if the program runs.
 *
 * Description: If the function fails or
 * the file is not an ELF return 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *head;
int op, rd;

op = open(argv[1], O_RDONLY);
if (op == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
head = malloc(sizeof(Elf64_Ehdr));
if (!head)
{
close_elf(op);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
rd = read(op, head, sizeof(Elf64_Ehdr));
if (rd == -1)
{
free(head);
close_elf(op);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}

check_for_elf(head->e_ident);
printf("ELF Header:\n");
magic_print(head->e_ident);
print_class(head->e_ident);
print_data(head->e_ident);
version_print(head->e_ident);
print_osabi(head->e_ident);
print_abi(head->e_ident);
print_type(head->e_type, head->e_ident);
entry_print(head->e_entry, head->e_ident);

free(head);
close_elf(op);
return (0);
}

