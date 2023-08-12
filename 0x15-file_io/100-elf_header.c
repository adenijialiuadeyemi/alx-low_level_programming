#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_for_elf(unsigned char *eid);
void magic_print(unsigned char *eid);
void print_class(unsigned char *eid);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int typ, unsigned char *e_ident);
void entry_print(unsigned long int entr, unsigned char *e_ident);
void print_data(unsigned char *eid);
void version_print(unsigned char *eid);
void print_abi(unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_for_elf - To be sure whether a file is ELF.
 * @eid: Aiming to an array containing ELF nums.
 *
 * Description: return 98 when the file isnt ELF.
 */

void check_for_elf(unsigned char *eid)
{
	int ind;

	for (ind = 0; inde < 4; ind++)
	{
		if (eid[ind] != 127 &&
		    eid[ind] != 'E' &&
		    eid[ind] != 'L' &&
		    eid[ind] != 'F')
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

/**
 * print_data - ELF data is printed.
 * @eid: Aiming to an arr which contains the printed data.
 */
void print_data(unsigned char *eid)
{
	printf("ELF_Data: ");

	switch (eid[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<class_unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * version_print - ELF version is printed.
 * @eid: Aiming to an arr which contains ELF_version.
 */
void version_print(unsigned char *eid)
{
	 printf("ELF_Version: %d",eid[EI_VERSION]);

	switch (eid[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Output the OS_ABI of an ELF_header.
 * @e_ident: Targetting an array which has the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - Prints the ABI_version of an ELF_header.
 * @e_ident: Aiming an array which has ELF_ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
		e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry: The mem_location of the ELF_entry_point.
 * @e_ident: Aiming at an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
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
	header = malloc(sizeof(Elf64_Ehdr));
	if (!head)
	{
		close_elf(op);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	rd = read(op, header, sizeof(Elf64_Ehdr));
	if (rd == -1)
	{
		free(head);
		close_elf(op);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(head->e_ident);
	printf("ELF Header:\n");
	print_magic(head->e_ident);
	print_class(head->e_ident);
	print_data(head->e_ident);
	print_version(head->e_ident);
	print_osabi(head->e_ident);
	print_abi(head->e_ident);
	print_type(head->e_type, head->e_ident);
	print_entry(head->e_entry, head->e_ident);

	free(head);
	close_elf(op);
	return (0);
}

