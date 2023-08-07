#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define BUF_SIZE 64

void display_error(char *msg, int exit_code) {
    dprintf(STDERR_FILENO, "%s\n", msg);
    exit(exit_code);
}

void display_elf_header(const Elf64_Ehdr *header) {
   int i;
       	printf("ELF Header:\n");
    printf("  Magic:   ");

    for ( i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n", (header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" : "unknown data format");
    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        default: printf("<unknown: %d>\n", header->e_ident[EI_OSABI]); break;
    }
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (header->e_type) {
        case ET_NONE: printf("NONE (Unknown)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown: %x>\n", header->e_type); break;
    }
    printf("  Entry point address:               0x%lx\n", (unsigned long) header->e_entry);
}

int main(int argc, char *argv[]) {
   ssize_t bytes_read;
       	Elf64_Ehdr elf_header;
   int fd;
       	if (argc != 2) {
        display_error("Usage: elf_header elf_filename", 98);
    }

   fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        display_error("Error: Cannot open file", 98);
    }

 
     bytes_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));
    if (bytes_read != sizeof(Elf64_Ehdr)) {
        close(fd);
        display_error("Error: Cannot read ELF header", 98);
    }

    if (!(elf_header.e_ident[EI_MAG0] == ELFMAG0 &&
          elf_header.e_ident[EI_MAG1] == ELFMAG1 &&
          elf_header.e_ident[EI_MAG2] == ELFMAG2 &&
          elf_header.e_ident[EI_MAG3] == ELFMAG3)) {
        close(fd);
        display_error("Error: Not an ELF file", 98);
    }

    display_elf_header(&elf_header);

    close(fd);
    return 0;
}

