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
	bool single = false;

	if (format != NULL)
	{
		va_start(list, format);

		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i]  == '%')
			{
				check_format_specifier(list, format[i + 1],
						&n, s, &i, j, &single);
			}
			else
			{
				if (single == false)
					n += _putchar(format[i]);
			}
		}
		va_end(list);
	}
	else
		n = -1;
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
 * @find: A boolean checking whether % is find alone
 */
void check_format_specifier(va_list list, char c,
		int *n, char *s, int *i, int j, bool *find)
{
	if (c == 'c')
	{
		_putchar(va_arg(list, int));
		++*i;
		if (*find == false)
		++*n;
	}
	else if (c == 's')
	{
		s = va_arg(list, char *);
		if (s == NULL)
			s = "(null)";
		if (s != NULL)
		{
			j = 0;
			while (s[j] != '\0')
			{
				_putchar(s[j]);
				j++;
				if (*find == false)
					++*n;
			}
		}
		++*i;
	}
	else if (c  == '%')
	{
		_putchar(37);
		++*i;
		if (*find == false)
			++*n;
	}
	else
		check_non_format_specifier(c, &find, &n, &i);
}
/**
 * check_non_format_specifier - Check a non format specifier
 * @c: The next char following %
 * @find: A bool to check wheteher % is alone
 * @n: The number of character of the format string
 * @i: The loop counter
 */
void check_non_format_specifier(char c, bool **find, int **n, int **i)
{
	if (c != 32 && c != '\0')
	{
		_putchar(37);
		_putchar(c);
		++**i;
		if (**find == false)
		{
			++**n;
			++**n;
		}
	}
	else
	{
		if (**find == false)
		{
			**find = true;
			**n = -1;
		}
	}

}
