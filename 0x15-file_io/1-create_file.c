#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
/**
 * create_file - main function.
 *@filename: take the input from user.
 *@text_content: take the input from user.
 * Return: value.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;

	if (filename == NULL)
	return (-1);


	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (fd == -1)
	return (-1);

	if (text_content != NULL)
	{
	ssize_t bytes_written = write(fd, text_content, strlen(text_content));

	if (bytes_written == -1)
	{
	close(fd);
	return (-1);
	}
	}

	close(fd);
	return (1);
}
