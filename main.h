#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdbool.h>
int _printf(const char *format, ...);
int _putchar(char c);
void check_format_specifier(va_list list, char c,
		int *n, char *s, int *i, int j, bool *single);
#endif
