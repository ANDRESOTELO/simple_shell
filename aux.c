#include "header.h"

/**
 * _split_string - Function to splir an array in tokens
 *@str: string from buffer.
 *@delim: character to create tokens
 * Return: an array splited by tokens to success
 */

char **_split_string(char *str, char *delim)
{

	int i = 0, x = 0;
	char **array = NULL, *token = NULL, *token2;
	char *str_copy = NULL;

	str_copy = _strdup(str);

	token = _strtok(str_copy, delim);

	while (token)
	{
		token = _strtok(NULL, delim);
		i++;
	}
	free(str_copy);

	str_copy = _strdup(str);
	token2 = _strtok(str_copy, delim);
	array = malloc(sizeof(char *) * (i + 1));

	while (token2)
	{
		array[x] = _strdup(token2);
		token2 = _strtok(NULL, delim);
		x++;
	}
	array[x] = NULL;

	free(token);
	free(token2);
	free(str_copy);
	return (array);
}


/**
 * _string_directory - Split a string in tokens for each directory in the path.
 *
 * @argv: array to concatenate with directory and /.
 *
 * Return: On succes string concatenated 0r NULL if fails.
*/

char *_string_directory(char **argv)
{
	struct stat st;
	int i = 0, j = 0, k = 0;
	char **token_path = NULL, *p = NULL, *path = NULL;

	path = _getenv("PATH");
	if (path == NULL)
		return (0); /*Otro cambio*/
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


/**
 * _strtok - Funtion to create an array of tokens.
 *
 * @str: Command from the user imput.
 * @delim: Delimiter.
 *
 * Return: Always return 0.
 */

char *_strtok(char *str, const char *delim)
{
	const char *org = delim;
	int isEqual = 1, isGetInto = 0;
	static char *step, *stepNull;
	static int isEnd;

	if (str)
		isEnd = 0;
	if (isEnd)
		return (NULL);
	step = (str) ? str : (stepNull + 1);
	if (str)
		stepNull = str;
	else
		str = step;
	while (*str && isEqual)
	{
		isEqual = 0;
		for (delim = org; *delim; delim++)
			if (*str == *delim)
				isEqual = 1;
		str = (!isEqual) ? str : str + 1;
		isEnd = (*str) ? 0 : 1;
		if (isEnd)
			return (NULL);
	}
	step = str;
	while (*str && !isEqual)
	{
		isEqual = 0;
		for (delim = org; *delim; delim++)
			if (*str == *delim)
			{
				isGetInto = 1, isEqual = 1;
				isEnd = (*(str + 1)) ? 0 : 1, *str = '\0';
			}
		str = (isEqual) ? str : str + 1;
		if (!isGetInto && !*str)
			isEnd = 1;
	}
	return (stepNull = str, step);
}
