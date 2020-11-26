#include "soleo.h"

/**
 * _token - Function to split a strink by tokens
 *
 * @array: array to save all tokens
 *e
 * Return: string divided by token to success
 */

char *_token(char *array[])
{
	char *token = NULL;

	if (array[0][0] == '/' || array[0][0] == ' ')
	{
		if (array[0][0] == ' ')
		{
			token = _string_directory(array);
			return (token);
		}
		else
		{
			token = array[0];
		}

	}
	else
	{
		token = _string_directory(array);
	}
	return (token);
}

/**
 * _strdup - Function that duplicate an array
 * with a new apce in memory
 * @str: string to duplicated
 * Return: duplicated string to succes or NULL from error
 */

char *_strdup(char *str)
{
	char *copy;
	int index = 0, len = 0;

	if (str == NULL)
		return (NULL);

	for (index = 0; str[index]; index++)
		len++;

	copy = malloc(sizeof(char) * (len + 1));

	if (copy == NULL)
		return (NULL);

	for (index = 0; str[index]; index++)
		copy[index] = str[index];

	copy[len] = '\0';

	return (copy);
}

/**
 * _strcmp - to compare two string
 *@s1: value waited from the main.c
 *@s2: source to be compare
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int c = 0, x = 0;

	for (c = 0; s1[c] != '\0' && s2[c] != '\0'; c++)
	{
		if (s1[c] == s2[c])
			x = 0;
		else
			return (s1[c] - s2[c]);
	}
	return (x);
}
