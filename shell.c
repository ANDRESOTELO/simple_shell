#include "soleo.h"

/**
 * main - Entry point of simple_shell
 * @ac: arguments count.
 * @argv: arguments value
 * Return: Always return 0.
 */

int main(int ac, char *argv[])
{
	size_t nbytes = 0;
	int r_bytes = 0, count_w = 0;
	char *buffer = NULL, **array = NULL, *token = NULL;
	char *xclose[] = {"exit", NULL};
	(void)ac, (void)argv;

	if (isatty(STDIN_FILENO) != 0)
		write(STDOUT_FILENO, "\033[94m$: \033[0m", 7);

	signal(SIGINT, _ctrl_c);
	while ((r_bytes = getline(&buffer, &nbytes, stdin)) != -1 && ++count_w)
	{
		if (r_bytes != 1) /*enter line*/
		{
			buffer[r_bytes - 1] = '\0';
			if (_print_env(buffer) == -1)
			{
				if (_strcmp(buffer, xclose[0]) == 0)
					free(buffer), exit(0);

				array = _split_string(buffer, " ");
				token = _token(array);
				if (token == NULL)
					token = array[0];

				_exec(count_w, token, array);
			}
		}
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\033[94m$: \033[0m", 7);
	}
	if (isatty(STDIN_FILENO) != 0)
	write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	return (0);
}
