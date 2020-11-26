#include "soleo.h"

/**
 * _string_directory - Split PATH in tokens
 * @argv: array to concatenate with directory
 * Return: On succes string concatenated or NULL if fails.
 */

char *_string_directory(char **argv)
{
	struct stat st;
	int i = 0, j = 0, k = 0;
	char **token_path = NULL, *p = NULL, *path = NULL;

	path = _getenv("PATH");
	if (path == NULL)
		return (0);
	if (path[0] == ':')
		path = _hack_path(path);

	token_path = _split_string(path, ":");
	i = 0;
	while (token_path[i])
	{
		for (j = 0; token_path[i][j]; j++)
			;
		for (k = 0; argv[0][k]; k++)
			;
		p = malloc(sizeof(char) * (j + k + 2));
		if (!p)
			perror("Error"), _sfree(token_path), exit(0);

		for (j = 0; token_path[i][j]; j++)
			p[j] = token_path[i][j];
		p[j] = '/';
		for (k = 0; argv[0][k]; k++)
			p[j + k + 1] = argv[0][k];
		p[j + k + 1] = '\0';

		if (stat(p, &st) == 0)
		{
			_sfree(token_path);
			return (p);
		}
		i++;
		free(p);
	}
	_sfree(token_path);
	return (NULL);
}
