#include "main.h"
<<<<<<< HEAD
/**
  * print_fmtd - take string and print formatted string
  * @format: whole str
  * @list: letter specifiers ... d
  * @ap: all args passed
  *
  * Return: int
  */
int print_fmtd(const char *format, fts list[], va_list ap)
{
	int i, j, argvs, total = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; list[j].flag != NULL; j++)
			{
				if (format[i + 1] == list[j].flag[0])
				{
					argvs = list[j].fptr(ap);
					if (argvs == -1)
						return (-1);
					total += argvs;
					break;
				}
			}
			if (list[j].flag == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_write_ch(format[i]);
					_write_ch(format[i + 1]);
					total += 2;
				}
				else
					return (-1);
			}
			i += 1;
		}
		else
		{
			_write_ch(format[i]);
			total++;
		}
	}
	return (total);
}
/**
  * _printf - produce output according to format
  * @format: char str
  *
  * Return: int
  */
int _printf(const char *format, ...)
{
	int total;

	fts list[] = {
		{"c", print_ch},
		{"s", print_str},
		{"%", print_pcnt},
		{"d", print_d},
		{"i", print_i},
		{"b", print_to_bin},
		{"p", print_p},
		{"o", print_o},
		{"u", print_u},
		{NULL, NULL}
	};

	va_list ap;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	total = print_fmtd(format, list, ap);
	va_end(ap);
	return (total);
=======

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
>>>>>>> d79ecf0c2b35447192f90443ff0102f1ed9a7d22
}
