#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - 1Megabyte is kept for a buffer.
 * @file: aiming at the filename.
 *
 * Return: A ptr to the new buffer which is created.
 */

char *create_buffer(char *file)
{
char *buff;

buff = malloc(sizeof(char) * 1024);

if (!buff)
{
dprintf(STDERR_FILENO, "Unable to write to %s\n", file);
exit(99);
}
return (buff);
}

/**
 * close_file - The file is closed.
 * @fd: aiming at the file_descriptor
 */

void close_file(int fd)
{
int cl;

cl = close(fd);

if (cl == -1)
{
dprintf(STDERR_FILENO, "file_descriptor %d is unable to close\n", fd);
exit(100);
}
}

/**
 * main - The contents of a file is moved to another.
 * @argc: count of total args.
 * @argv: Aiming at the content of the arr.
 *
 * Return: if no error 0.
 *
 * Description: return 97 when error on arg_count is encountered.
 * return 98 when the file from is anot available
 * return 99 if we are unable to create a file
 * return 100 if we are unable to close a file.
 */

int main(int argc, char *argv[])
{
int src, dest, rd, wr;
char *buff;

if (argc != 3)
{
dprintf(STDERR_FILENO, "copy file from src to dest\n");
exit(97);
}

buff = create_buffer(argv[2]);
src = open(argv[1], O_RDONLY);
rd = read(src, buff, 1024);
dest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

do {
if (src == -1 || rd == -1)
{
dprintf(STDERR_FILENO, "Unable to read %s\n", argv[1]);
free(buff);
exit(98);
}

wr = write(dest, buff, rd);
if (dest == -1 || wr == -1)
{
dprintf(STDERR_FILENO, "Unable to write in %s\n", argv[2]);
free(buff);
exit(99);
}

rd = read(src, buff, 1024);
dest = open(argv[2], O_WRONLY | O_APPEND);

} while (rd > 0);
free(buff);
close_file(src);
close_file(dest);

return (0);
}

