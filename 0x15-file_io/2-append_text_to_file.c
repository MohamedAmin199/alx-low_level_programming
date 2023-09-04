#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The tring to add at the end of the file.
 * Return: 1 on success and -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, a, b = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0600);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[b])
			b++;

		a = write(fd, text_content, b);
		if (a != b)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);

	return (1);
}
