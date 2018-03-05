#include <unistd.h>
#include <stdio.h>
#include "header.h"

void 	my_putchar(char c)
{
  write(1, &c, 1);
}

void 	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar(*str);
      str = str + 1;
    }
}

int      isnegatif(int n)
{
  if (n < 0)
    {
      n = -n;
      my_putchar('-');
    }
  return (n);
}

int 	is_number(char *str)
{
   while (*str)
   {
       if (!digit(*str++))
            return (1);   
   }     
   return (0);
}

void    	my_putnbr(int n)
{
  int     tab[10];
  int     i;

  i = 0;
  n = isnegatif(n);
  if (n == 0)
    {
      my_putchar(48);
      return ;
    }
  while (n > 0)
    {
      tab[i] = (n%10);
      n = (n / 10);
      i++;
    }
  i--;
  while (i >= 0)
    {
      my_putchar((tab[i])+48);
      i--;
    }
}