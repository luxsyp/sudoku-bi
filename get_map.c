/*
** sud_map.c for sudoku in /u/all/kim_r/cu/public/Grp/Sudoku/refait
**
** Made by richard kim
** Login   <kim_r@epitech.net>
**
** Started on  Sat Apr 24 11:47:59 2010 richard kim
** Last update Sun Apr 25 21:25:07 2010 richard kim
*/

#include	"sudo.h"
#include	<string.h>

int		**get_map(int **tab)
{
  char		*s;
  int		i;
  int		j;
  int		k;

  j = 0;
  while (j < 9)
    {
      k = 0;
      i = 2;
      s = get_next_line(0);
      while (k < 9)
	{
	  if (s && s[i] >= '1' && s[i] <= '9')
	    tab[j][k] = s[i] - '0';
	  else if (s && s[i] == ' ')
	    tab[j][k] = 0;
	  k += 1;
	  i += 2;
	}
      j += 1;
    }
  s = get_next_line(0);
  free(s);
  return (tab);
}

void		aff_tab(int **tab)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  my_putstr("|------------------|\n");
  while (tab && j < 9)
    {
      my_putchar('|');
      while (i < 9)
	{
	  my_putchar(' ');
	  my_putnbr(tab[j][i]);
	  i += 1;
	}
      i = 0;
      j += 1;
      my_putchar('|');
      my_putchar('\n');
    }
  my_putstr("|------------------|\n");
}

int		**malloc_tab(int **tab)
{
  int		i;

  i = 0;
  tab = xmalloc(9 * sizeof(*tab));
  while (i < 9)
    {
      tab[i] = xmalloc(9 * sizeof(**tab));
      memset(tab[i], '\0', 10);
      i += 1;
    }
  return (tab);
}

void		free_tab(int **tab)
{
  int		i;

  i = 0;
  while (i < 9)
    {
      free(tab[i]);
      i += 1;
    }
  free(tab);
}
