#include "soleo.h"

/**
 * _exec - Funtion to execute program.
 *
 * @token: Command from the user imput.
 * @array: arguments for the program to execute.
 * @count_w: holis.
 *
 * Return: Always return 0.
 */

int _exec(int count_w, char *token, char *array[])
{
	struct stat st;
	pid_t child = 0;

	if (stat(token, &st) == 0)
	{
		child = fork();
		if (child == -1)
			free(token),
			perror("Error"), exit(0);

		if (child == 0)
		{
			if (execve(token, array, NULL) == -1)
				perror("Error Execve"), exit(0);
		}
		else
		{
			wait(NULL);
			if (token != array[0])
				free(token);
			_sfree(array);

		}
	}
	else
	{
		_error(count_w, array);
		_sfree(array);
	}
	return (0);
}

/**
 * _print_env - Function to print env
 * @buffer: string from buffer to compare
 * Return: 1 for success or -1 for error
 */

int _print_env(char *buffer)
{

	int i = 0, j = 0;
	char *key_word[] = {"env", NULL};
	char *env_token = NULL;

	if (buffer[0] == ' ')
		env_token =	_strtok(buffer, " ");
	else
	{
		env_token = buffer;
	}

	if (_strcmp(env_token, key_word[0]) == 0)
	{
		while (environ[i])
		{
			for (j = 0; environ[i][j]; j++)
			;
			write(1, environ[i], j);
			write(1, "\n", 1);
			i++;
		}
		return (1);
	}
return (-1);
}


/**
 *_ctrl_c - function to capture interruption signal
 *@sig: signal variable
 *Return: void
 */
void _ctrl_c(int sig)
{
	(void)sig;
	write(STDERR_FILENO, "\n", 1);
	write(STDOUT_FILENO, "\033[94m$: \033[0m", 16);
}

/**
 * _getenv - Function to get de enviroment
 * @name:string from buffer
 * Return: PATH to succes or NULL for error
 */
char *_getenv(char *name)
{
	int i = 0, j = 0;
	char *null = "(null)";

	char *path = NULL;

	for (j = 0; name[j]; j++)
	;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (!_strcmp(environ[i], name))
		{
			path = (environ[i] + (j + 1));
			return (path);
		}
	}
	return (null);
}
