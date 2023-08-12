#include "main.h"

/**
 * create_file - Getting a file created.
 * @filename: aiming at the filename.
 * @text_content: Aiming at the string to be written.
 *
 * Return:  -1 if an error occured.
 *        but if no error occured return 1.
 */

int create_file(const char *filename, char *text_content)
{
int file_open, o, l = 0;

if (!filename)
	return (-1);
file_open = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (text_content == NULL)
	text_content = "";
for (l = 0; text_content[l]; l++)
;
o = write(file_open, text_content, l);

if (file_open == -1 || o == -1)
	return (-1);

close(file_open);
return (1);
}

