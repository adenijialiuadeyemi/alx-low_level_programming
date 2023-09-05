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
