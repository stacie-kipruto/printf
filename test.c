#include "main.h"
/**
  * print_num - display num
  * @ap: list of args
  *
  * Return: num of args displayed
  */
int print_num(va_list ap)
{
  int n, d, ln;
  unsigned int num;
  
  n  = va_arg(ap, int);
  d = 1;
  ln = 0;
  if (n < 0)
  {
    ln += _write_ch('-');
    num = n * -1;
  }
  else
    num = n;
  for (; num / d > 9; )
    d *= 10;
  for (; d != 0; )
  {
    ln += _write_ch('0' + num / d);
    num %= d;
    d /= 10;
  }
  return (ln);
}
/**
  * print_int - display int
  * @ap: list of args
  *
  * Return: amnt of nums displayed
  */
int print_int(va_list ap)
{
  int ln;
  
  ln = print_num(ap);
  return (ln);
}
