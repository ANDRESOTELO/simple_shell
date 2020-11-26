#include "soleo.h"

/**
 * _strtok - Funtion to create an array of tokens.
 * @str: Command from the user imput.
 * @delim: Delimiter to break each token
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
