#include "main.h"

/**
 * append_text_to_file - A sting is appnded.
 * @filename: Aiming at the filename.
 * @text_content: The text added
 * Return: -1 if an error occurs.
 *        return  -1 whe the document is not present
 *       but return 1 if any other error occurs.
 */

int append_text_to_file(const char *filename, char *text_content)
{
int rd, wr, l = 0;

if (!filename)
return (-1);
if (text_content)
{
for (l = 0; text_content[l];)
l++;
}

rd = open(filename, O_WRONLY | O_APPEND);
wr = write(rd, text_content, l);

if (rd == -1 || wr == -1)
return (-1);

close(rd);

return (1);
}

