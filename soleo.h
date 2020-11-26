#ifndef __SOLEO_H__
#define __SOLEO_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

/* string */
char *_token(char **array);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

/* auxiliar functions*/
char **_split_string(char *str, char *delim);
char *_string_directory(char **argv);
char *_strtok(char *str, const char *delim);

/* exec */
int _exec(int count_w, char *token, char *array[]);
int _print_env(char *buffer);
char *_getenv(char *name);
void _ctrl_c(int sig);

/* final */
void _error(int count_w, char *array[]);
char *_itoa(int integer);
void _sfree(char **i_want_to_be_free);
char *_hack_path(char *path);

/* advanced */

char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _getline(char **buffer, size_t *bufsize, int fd);

#endif
