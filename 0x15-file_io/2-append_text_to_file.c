#include "main.h"

/**
 * append_text_to_file - This function adds str of chars at the end of a file.
 * @filename: file pointer.
 * @text_content: string to be appended
 *
 * Return: 1 when successful, -1 when failed.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, ret_write, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	ret_write = write(o, text_content, len);

	if (fd == -1 || ret_write == -1)
		return (-1);

	close(fd);

	return (1);
}

