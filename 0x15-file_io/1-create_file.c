#include "main.h"

/**
 * create_file - This function creates_a_file.
 * @filename: Aiming at the file to be created
 * @text_content: Str Pointer
 *
 * Return: -1 when fails, otherwise return 1
 */
int create_file(const char *filename, char *text_content)
{
	int fd, ret_write, str_len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (str_len = 0; text_content[str_len];)
			str_len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, len);

	if (fd == -1 || ret_write == -1)
		return (-1);

	close(fd);

	return (1);
}

