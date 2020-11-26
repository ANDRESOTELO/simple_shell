#include "soleo.h"

/**
 * _split_string - Function to split an array in tokens
 *@str: buffer info
 *@delim: character to create tokens
 * Return: an array of tokens to success
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
