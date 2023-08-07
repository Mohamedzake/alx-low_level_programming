#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void display_elf_header(const Elf64_Ehdr *elf_header);

int main(int argc, char *argv[]) {
    const char *elf_filename;
    int fd;
    Elf64_Ehdr elf_header;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    elf_filename = argv[1];
    fd = open(elf_filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening ELF file");
        return 98;
    }

    if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
        perror("Error reading ELF header");
        close(fd);
        return 98;
    }

    display_elf_header(&elf_header);

    close(fd);
    return 0;
}

void display_elf_header(const Elf64_Ehdr *elf_header) {
    int i;

    printf("ELF Header:\n  Magic:   ");
    for (i = 0; i < EI_NIDENT; ++i) {
        printf("%02x ", elf_header->e_ident[i]);
    }
    printf("\n");

    printf("  Class:                             ");
    if (elf_header->e_ident[EI_CLASS] == ELFCLASS32) {
        printf("ELF32\n");
    } else if (elf_header->e_ident[EI_CLASS] == ELFCLASS64) {
        printf("ELF64\n");
    } else {
        printf("Unknown\n");
    }

    printf("  Data:                              ");
    if (elf_header->e_ident[EI_DATA] == ELFDATA2LSB) {
        printf("2's complement, little endian\n");
    } else if (elf_header->e_ident[EI_DATA] == ELFDATA2MSB) {
        printf("2's complement, big endian\n");
    } else {
        printf("Unknown\n");
    }

    printf("  Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    switch (elf_header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
      
        default: printf("Unknown\n"); break;
    }

    printf("  ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (elf_header->e_type) {
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
      
        default: printf("Unknown\n"); break;
    }

    printf("  Entry point address:               0x%lx\n", (unsigned long)elf_header->e_entry);
}

