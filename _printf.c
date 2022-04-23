#include "main.h"
/**
 * _printf - Print anything on the string
 * @format: A set of characters with conversion specifiers
 * Return: The number of
 */
int _printf(const char *format, ...)
{
	int i = 0, j = 0, n = 0;
	va_list list;
	char *s = NULL;

	if (format != NULL)
	{
		va_start(list, format);

		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i]  == '%')
			{
				check_format_specifier(list, format[i + 1], n, s, &i, j);
			}
			else
				n += _putchar(format[i]);
		}
		va_end(list);
	}
	return (n);
}

/**
 * check_format_specifier - Format the string to pring
 * @list: The list of the variadic function (arguments
 * @c: The char containing the format specifier
 * @n: The number of element of the string to print
 * @s: A pointer to a string to print
 * @i: The counter of the loop
 * @j: The counter of the string loop
 */
void check_format_specifier(va_list list, char c,
		int n, char *s, int *i, int j)
{
	if (c == 'c')
	{
		n += _putchar(va_arg(list, int));
		++*i;
	}
	else if (c == 's')
	{
		s = va_arg(list, char *);
		if (s != NULL)
		{
			j = 0;
			while (s[j] != '\0')
			{
				n += _putchar(s[j]);
				j++;
			}
		}
		++*i;
	}
	else if (c  == '%' || c == '\0'
			|| c == '\n')
	{
		n += _putchar(37);
		if (c == '\n')
			_putchar('\n');
		++*i;
	}
}
