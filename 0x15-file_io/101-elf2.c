#include "main.h"

/**
 * print_data - ELF data is printed.
 * @eid: Aiming to an arr which contains the printed data.
 */
void print_data(unsigned char *eid)
{
printf("ELF_Data: \n");
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
	printf("<class_unknown: %x>\n", eid[EI_CLASS]);
}
}
/**
 * version_print - ELF version is printed.
 * @eid: Aiming to an arr which contains ELF_version.
 */
void version_print(unsigned char *eid)
{
printf("ELF_Version: %d", eid[EI_VERSION]);
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
printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
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

