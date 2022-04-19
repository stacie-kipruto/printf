#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: a pointer to the format string
 *
 * Return: on success, returns the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	char *p;
	char *start;
	int count = 0;

	va_start(args, format);


	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		return (-1);
	}

	for (p = (char *)format; *p; p++)
	{
		if (*p != '%')
		{
			count += _putchar(*p);
			continue;
		}
		start = p;
		++p;
		if (!get_specifier(p))
		{
			count += print_from_to(start, p, 0);
		}
		else
		{
			count += get_print_func(p, args);
		}

	}
	va_end(args);
	return (count);
}
