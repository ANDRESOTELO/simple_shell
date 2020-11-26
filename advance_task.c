#include "soleo.h"
#define BSIZE 4

/**
 * _memset - Function to set a . at the begining of a string.
 *
 * @s: string from buffer
 * @b: string from buffer
 * @n: string from buffer
 *
 * Return: string with a . at the begining of a string.
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * _memcpy - Function to set a . at the begining of a string.
 *
 * @dest: string from buffer
 * @src: string from buffer
 * @n: string from buffer
 *
 * Return: string with a . at the begining of a string.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * _realloc - Function to set a . at the begining of a string.
 *
 * @ptr: string from buffer
 * @old_size: string from buffer
 * @new_size: string from buffer
 *
 * Return: string with a . at the begining of a string.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *ptr2;

	if (old_size == new_size)
		return (ptr);

	if (ptr == NULL)
	{
		ptr2 = malloc(new_size);
		if (ptr2 == 0)
			return (0);
		free(ptr);
		return (ptr2);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (0);
	}

	ptr2 = malloc(new_size);

	if (ptr2 == 0)
		return (0);

	ptr2 = _memset(ptr2, '\0', new_size);

	_memcpy(ptr2, ptr, old_size);
	free(ptr);
	return (ptr2);
}

/**
 * _getline - Function to set a . at the begining of a string.
 *
 * @buffer: string from buffer
 * @bufsize: string from buffer
 * @fd: string from buffer
 *
 * Return: string with a . at the begining of a string.
 */


int _getline(char **buffer, size_t *bufsize, int fd)
{
	static char *buff;
	static size_t size;
	unsigned int len = 0, i = 0, sizeold;
	int r;

	if (*bufsize == 0)
		size = BSIZE;
	if (*buffer == 0)
	{
		buff = malloc(sizeof(char) * size);
		if (!buff)
			return (write(2, "Memory Error", 22), 0);
		*buffer = buff;
	}
	buff = _memset(buff, '\0', size);
	do {

		r = read(fd, buff + len, BSIZE);
		if (r >= 0)
			i = len, len += r;
		if (r == -1 || r == 0)
			return (-1);
		if  (len >= size)
		{
			sizeold = size, size += BSIZE;
			buff = _realloc(buff, sizeold, size);
			if (!buff)
				return (write(2, "Memory Error", 22), 0);
		}
		for (; i < len; i++)
		{
			if (buff[i] == '\n')
			{
				*buffer = buff, *bufsize = size;
				return (len);
			}
		}

	} while (1);
	return (len);
}
