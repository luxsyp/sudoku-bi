/*
** usual_func.c for rush in /u/all/kim_r/cu/public/Grp/Sudoku
**
** Made by richard kim
** Login   <kim_r@epitech.net>
**
** Started on  Sat Apr 24 00:52:22 2010 richard kim
** Last update Sat Apr 24 01:49:23 2010 richard kim
*/

#include	"sudo.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str)
    while (str[i])
      i += 1;
  return (i);
}

void		my_putstr(char *str)
{
  xwrite(1, str, my_strlen(str));
}

void		my_putnbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if (nb > 9)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + 48);
}

void		my_puterror(char *str)
{
  xwrite(2, str, my_strlen(str));
}

void		my_putchar(char c)
{
  xwrite(1, &c, 1);
}

