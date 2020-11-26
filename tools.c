#include "soleo.h"

/**
 * _error - Funtion to execute program.
 *
 * @count_w: Command from the user imput.
 * @array: arguments for the program to execute.
 *
 * Return: Always return 0.
 */

void _error(int count_w, char *array[])
{
	int i = 0;
	char *print_c = NULL;

	print_c = _itoa(count_w);

	for (i = 0; print_c[i]; i++)
	;

	write(STDERR_FILENO, "\033[94m$: \033[0m", 17);
	write(STDERR_FILENO, print_c, i); /* by Andy.*/
	write(STDERR_FILENO, ": ", 2);

	for (i = 0; array[0][i]; i++)
	;

	write(STDERR_FILENO, array[0], i);
	write(STDERR_FILENO, ": not found\n", 12);
	free(print_c);
}

/**
 * _itoa - Funtion to execute program.
 *
 * @count_w: Command from the user imput.
 *
 * Return: Always return 0.
 */
char *_itoa(int count_w)
{
	char *numstr;
	unsigned int tmp, digits;

	tmp = count_w;
	for (digits = 0; tmp != 0; digits++)
		tmp /= 10;
	numstr = malloc(sizeof(char) * (digits + 1));
	if (numstr == NULL)
	{
		perror("Fatal Error1");
		exit(0); /** Aqui modificado exit(127)*/
	}
	numstr[digits] = '\0';
	for (--digits; count_w; --digits)
	{
		numstr[digits] = (count_w % 10) + '0';
		count_w /= 10;
	}
	return (numstr);
}


/**
 * _hack_path - Function to set a . at the begining of a string.
 *
 * @path: string from buffer
 *
 * Return: string with a . at the begining of a string.
 */

char *_hack_path(char *path)
{
	char *path2 = NULL;
	char *path_cpy = NULL;
	int i = 0;

	path_cpy = _strdup(path);

	for (; path[i] != '\0'; i++)
	;
	path2 = malloc(sizeof(char) * i + 2);
	if (!path2)
	{
		free(path_cpy);
		exit(0);
	}

	path2[0] = '.';

	for (i = 0; path_cpy[i] != '\0'; i++)
	{
		path2[i + 1] = path_cpy[i];
	}
	path2[i] = '\0';

	free(path_cpy);
	return (path2);
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
