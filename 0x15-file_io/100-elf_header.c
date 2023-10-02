#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

#define BUFFER_SIZE 128

void print_error(char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}

void print_elf_header(Elf64_Ehdr *header) {
    int i;
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x", header->e_ident[i]);
        if (i < EI_NIDENT - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
    printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Solaris\n");
            break;
        case ELFOSABI_AIX:
            printf("AIX\n");
            break;
        case ELFOSABI_IRIX:
            printf("IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("TRU64\n");
            break;
        case ELFOSABI_MODESTO:
            printf("Novell - Modesto\n");
            break;
        case ELFOSABI_OPENBSD:
            printf("OpenBSD\n");
            break;
        default:
            printf("<unknown: %d>\n", header->e_ident[EI_OSABI]);
    }
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (header->e_type) {
        case ET_NONE:
            printf("No file type\n");
            break;
        case ET_REL:
            printf("Relocatable file\n");
            break;
        case ET_EXEC:
            printf("Executable file\n");
            break;
        case ET_DYN:
            printf("Shared object file\n");
            break;
        case ET_CORE:
            printf("Core file\n");
            break;
        default:
            printf("<unknown: %d>\n", header->e_type);
    }
    printf("  Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[]) {
	char *filename = argv[1];
    int fd;

Elf64_Ehdr elf_header;

    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
  }
  

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        print_error("Cannot open file");
    }

    if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
        print_error("Cannot read ELF header");
    }

    if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0) {
        print_error("Not an ELF file");
    }

    print_elf_header(&elf_header);
    close(fd);
    return 0;
}

