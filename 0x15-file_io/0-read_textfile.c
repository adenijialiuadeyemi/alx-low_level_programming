#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- The std output was printed.
 * @filename: aiming at the filename to be read
 * @letters: count of letters
 * Return: w- byte number
 * return 0 when error ocurs.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t file_open;
	ssize_t o;
	ssize_t r;

	file_open = open(filename, O_RDONLY);
	if (file_open == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	r = read(file_open, buffer, letters);
	o = write(STDOUT_FILENO, buf, t);

	free(buffer);
	close(file_open);
	return (o);
}

