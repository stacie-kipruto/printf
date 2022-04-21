#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

/**
  * struct fmtspec - format specifiers
  *
  * @flag: c, s, f, d ...
  * @fptr: function pointer
  */
struct fmtspec
{
	char *flag;
	int (*fptr)(va_list);
};

typedef struct fmtspec fts;

int _printf(const char *format, ...);
int _putchar(char c);
int print_percent(va_list ap);
int get_print_func(char *s, va_list ap);
int (*get_specifier(char *s))(va_list ap);
int print_string(va_list ap);
int _puts(char *str);
int print_from_to(char *start, char *stop, char *except);
int print_char(va_list ap);
char *convert(long int num, int base, int flags);
int print_number(char *str);
int print_number_right_shift(char *str);
int print_int(va_list ap);
int _strlen(char *s);



#endif /* MAIN_H */
