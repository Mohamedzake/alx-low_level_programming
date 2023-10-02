#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * error_exit - Prints an error message to stderr and exits with a status code.
 * @msg: The error message to print.
 * @status: The exit status code.
 */
void error_exit(const char *msg, int status)
{
    fprintf(stderr, "%s\n", msg);
    exit(status);
}

/**
 * print_elf_header - Prints information from the ELF header of a given file.
 * @filename: The name of the ELF file to read and print the header from.
 */
void print_elf_header(const char *filename)
{
    int fd;
    ssize_t n;
    Elf64_Ehdr header;
	int i;
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        error_exit("Error: Cannot open file", 98);

    n = read(fd, &header, sizeof(header));
    if (n == -1 || n != sizeof(header))
        error_exit("Error: Cannot read from file", 98);

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x%c", header.e_ident[i], i < EI_NIDENT - 1 ? ' ' : '\n');

    printf("  Class:                             ELF%d\n", header.e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);
    printf("  Data:                              %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
           (header.e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
            (header.e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
             (header.e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
              (header.e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "UNIX - FreeBSD" : "<unknown>")))));
    printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", header.e_type == ET_NONE ? "NONE (No file type)" :
           (header.e_type == ET_REL ? "REL (Relocatable file)" :
            (header.e_type == ET_EXEC ? "EXEC (Executable file)" :
             (header.e_type == ET_DYN ? "DYN (Shared object file)" :
              (header.e_type == ET_CORE ? "CORE (Core file)" : "<unknown>")))));
    printf("  Entry point address:               0x%lx\n", (unsigned long)header.e_entry);

    close(fd);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        error_exit("Usage: elf_header elf_filename", 98);

    print_elf_header(argv[1]);

    return 0;
}

