#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 64

/**
 * main - Displays the information contained in the ELF header of an ELF file.
 * @argc: The argument count.
 * @argv: The argument vector.
 * Return: 0 on success, or an exit code on failure.
 */
int main(int argc, char *argv[])
{
    int i,j,fd, bytes_read;
    unsigned char buffer[BUFFER_SIZE];

    if (argc != 2)
    {
        dprintf(2, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(2, "Error: Cannot read ELF file %s\n", argv[1]);
        exit(98);
    }

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read == -1)
    {
        dprintf(2, "Error: Cannot read ELF file %s\n", argv[1]);
        close(fd);
        exit(98);
    }

    printf("ELF Header:\n");
    for (i = 0; i < BUFFER_SIZE; i++)
    {
        printf("  Magic:   %02x", buffer[i]);
        for (j = 1; j < 16; j++)
        {
            printf(" %02x", buffer[i + j]);
        }
        printf("\n");
        i += 15;
    }

    close(fd);
    return (0);
}

