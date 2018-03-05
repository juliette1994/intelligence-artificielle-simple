#include "header.h"

int   digit(char caractere)
{
  int    ok;

  ok = 0;
  if (caractere >= 48 && caractere <= 57)
    ok = 1;
  return (ok);
}

int   my_getnbr(char *str)
{
  int   i;
  int   n;
  int   j;

  n = 0;
  j = 0;
  while ((str[j] == '-') || (str[j] == '+'))
      j++;
  if( j % 2 != 0)
     my_putchar('-');
  i = j;
  while ((str[i] >= 48) && (str[i] <= 57))
    {
      n = n * 10;
      n = n + (str[i] - '0');
      i++;
    }
  return (n);
}