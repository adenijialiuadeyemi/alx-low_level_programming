#include "main.h"

/**
 * read_textfile - This function reads a text file, then write it out
 * to the POSIX standard output
 * @filename: The pointer to the file
 * @letters: The Number of letters to read and print
 *
 * Return: The actual number of letters
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t num_read, num_written;
char *bufer;
if (!filename)
        return (0);
/* Opening the file */
fd = open(filename, O_RDONLY);
if (fd == -1)
        return (0);
/* Allocating Memory */
bufer = malloc(sizeof(char) * letters);
if (bufer == NULL)
        return(0);
/* Reading the file */
num_read = read(fd, bufer, letters);
/* Writing to a file */
num_written = write(STDOUT_FILENO, bufer, num_read);
/* Closing the file */
close(fd);
/* Getting read of buffer */
free(bufer);
/* Returning the num of letters written */
return (num_written);
}
