#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);

/**
 * print_class - Prints the class of an ELF header.
 * @elf_id: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *elf_id)
{
	printf("  Class:                             ");
	switch (elf_id[EI_CLASS])
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
		printf("<unknown: %x>\n", elf_id[EI_CLASS]);
	}
}

/**
 * print_data - Prints the data of an ELF header.
 * @elf_id: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *elf_id)
{
	printf("  Data:                              ");
	switch (elf_id[EI_DATA])
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
		printf("<unknown: %x>\n", elf_id[EI_CLASS]);
	}
}

/**
 * print_version - Prints the version of an ELF header.
 * @elf_id: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *elf_id)
{
	printf("  Version:                           %d",
			elf_id[EI_VERSION]);
	switch (elf_id[EI_VERSION])
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
 * print_abi - Prints the ABI version of an ELF header.
 * @elf_id: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *elf_id)
{
	printf("  ABI Version:                       %d\n",
			elf_id[EI_ABIVERSION]);
}
/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @elf_id: Aiming at an array of the ELF version.
 */
void print_osabi(unsigned char *elf_id)
{
	printf("  OS/ABI:                            ");

	switch (elf_id[EI_OSABI])
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
		printf("<unknown: %x>\n", elf_id[EI_OSABI]);
	}
}
/**
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @elf_id: Aiming at an array of the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *elf_id)
{
	if (elf_id[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf("  Type:                              ");
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
/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @elf_id: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *elf_id)
{
	printf("  Entry point address:               ");
	if (elf_id[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (elf_id[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}
/**
 * close_elf - Closes an ELF file.
 * @elf_fd: File descr of the ELF file.
 *
 * Description: Return 98 if fiile is unable to close
 */
void close_elf(int elf_fd)
{
	if (close(elf_fd) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Unable to close fd %d\n", elf_fd);
		exit(98);
	}
}
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

/**
 * main - Prints the ELF header info
 * @argc: Argument Count
 * @argv: Argument Vector
 *
 * Return: 0 when successful.
 *
 * Description:return 98.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *bufer;
	int fd, ret_read;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to read file %s\n", argv[1]);
		exit(98);
	}
	bufer = malloc(sizeof(Elf64_Ehdr));
	if (bufer == NULL)
	{
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error: Unable to read file %s\n", argv[1]);
		exit(98);
	}
	ret_read = read(fd, bufer, sizeof(Elf64_Ehdr));
	if (ret_read == -1)
	{
		free(bufer);
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error: `%s`: File doesnt exist\n", argv[1]);
		exit(98);
	}
	elf_chk(bufer->e_ident);
	printf("ELF Bufer:\n");
	print_magic(bufer->e_ident);
	print_class(bufer->e_ident);
	print_data(bufer->e_ident);
	print_version(bufer->e_ident);
	print_osabi(bufer->e_ident);
	print_abi(bufer->e_ident);
	print_type(bufer->e_type, bufer->e_ident);
	print_entry(bufer->e_entry, bufer->e_ident);
	free(bufer);
	close_elf(fd);
	return (0);
}
}
}
