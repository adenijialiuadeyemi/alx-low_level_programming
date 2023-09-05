#include "main.h"
char *create_buffer(char *file);
void close_file(char fd);
/**
 *create_buffer - Buffer Allocation
 *@filename: file pointer
 *Return: allocated buffer
 */
char *create_buffer(char *filename)
{
	char *bufer;

	bufer = malloc(sizeof(char) * 1024);
	if (bufer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (bufer);
}
/**
 *close_file - Closing a file
 *@fd: file_descr
 *Return: void
 */
void close_file(char fd)
{
	int count;

	count = close(fd);

	if (count < 0)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 *main - Main functio
 *@argc: Count of args
 *@argv: pointer to argument vectors
 *Return: 0 when successful
 */
int main(int argc, char *argv[])
{
	int sorce, destin, rd, wr;
	char *bufer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO,
				"Usage: cp file_from file_to\n");
		exit(97);
	}

	bufer = create_buffer(argv[2]);

	sorce = open(argv[1], O_RDONLY);
	rd =  read(sorce, bufer, 1024);
	destin = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (rd == -1 || sorce == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		wr = write(destin, bufer, rd);

		if (wr == -1 || destin == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			exit(99);
		}

		rd = read(sorce, bufer, 1024);
		destin = open(argv[2], O_WRONLY | O_APPEND);
	} while (rd > 0);

	free(bufer);
	close_file(sorce);
	close_file(destin);

	return (0);
}

