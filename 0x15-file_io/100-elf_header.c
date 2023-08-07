#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct {
    uint8_t e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint32_t e_entry;
    uint32_t e_phoff;
    uint32_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf32_Ehdr;

void display_elf_header(const Elf32_Ehdr *elf_header);

int main(int argc, char *argv[]) {
    const char *elf_filename;
    int fd;
    Elf32_Ehdr elf_header;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    elf_filename = argv[1];
    fd = open(elf_filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening ELF file");
        exit(98);
    }

    if (read(fd, &elf_header, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr)) {
        perror("Error reading ELF header");
        close(fd);
        exit(98);
    }

    display_elf_header(&elf_header);
    
    close(fd);
    return 0;
}

void display_elf_header(const Elf32_Ehdr *elf_header) {
    int i;

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < 16; ++i) {
        printf("%02x ", elf_header->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             ELF%d\n", elf_header->e_ident[4] == 1 ? 32 : 64);
    printf("  Data:                              %s\n", elf_header->e_ident[5] == 1 ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", elf_header->e_ident[6]);
    printf("  OS/ABI:                            ");
    switch (elf_header->e_ident[7]) {
        case 0: printf("UNIX - System V\n"); break;
        case 6: printf("UNIX - Solaris\n"); break;
        default: printf("<unknown: %d>\n", elf_header->e_ident[7]); break;
    }
    printf("  ABI Version:                       %d\n", elf_header->e_ident[8]);
    printf("  Type:                              ");
    switch (elf_header->e_type) {
        case 1: printf("REL (Relocatable file)\n"); break;
        case 2: printf("EXEC (Executable file)\n"); break;
        case 3: printf("DYN (Shared object file)\n"); break;
        default: printf("Unknown (%d)\n", elf_header->e_type); break;
    }
    printf("  Entry point address:               0x%08x\n", elf_header->e_entry);
}

