#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
/**
 * main - Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or an exit code on failure.
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to, read_result, write_result;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
	dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
	return (97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
	return (98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fd_to == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
	close(fd_from);
	return (99);
	}

	while ((read_result = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
	write_result = write(fd_to, buffer, read_result);
	if (write_result == -1 || write_result != read_result)
	{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
	close(fd_from);
	close(fd_to);
	return (99);
	}
	}

	if (read_result == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
	close(fd_from);
	close(fd_to);
	return (98);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close fd\n");
	return (100);
	}

	return (0);
}
