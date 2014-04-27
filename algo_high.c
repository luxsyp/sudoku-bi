/*
** algo_high.c for sudoku in /u/all/kim_r/cu/public/Grp/Sudoku/refait
**
** Made by richard kim
** Login   <kim_r@epitech.net>
**
** Started on  Sat Apr 24 12:46:06 2010 richard kim
** Last update Mon Apr 26 13:33:17 2010 damien locque
*/

#include	"sudo.h"
#include	<string.h>

int		check_square(int nb, int **map, int x, int y)
{
  int		j;
  int		i;
  int		tmp;

  j = (y / 3) * 3;
  i = (x / 3) * 3;
  x = i + 3;
  y = j + 3;
  tmp = i;
  while (j < y)
    {
      i = tmp;
      while (i < x)
	{
	  if (map[j][i] == nb)
	    return (0);
	  i++;
	}
      j++;
    }
  return (1);
}

int		check_line_col(int nb, int **map, int y, int x)
{
  int		i;

  i = 0;
  while (i < 9)
    {
      if (map[y][i] == nb)
	return (0);
      i++;
    }
  i = 0;
  while (i < 9)
    {
      if (map[i][x] == nb)
	return (0);
      i++;
    }
  return (1);
}

void		update(t_list *undone, int **map)
{
  int		i;

  if (undone)
    while (undone)
      {
	i = 1;
	memset(undone->val, 0, 10);
	while (i < 10)
	  {
	    if (check_line_col(i, map, undone->y, undone->x) == 1 &&
		check_square(i, map, undone->x, undone->y) == 1)
	      undone->val[i] = 1;
	    i++;
	  }
	undone = undone->next;
      }
}

int		complete_map(t_list *begin, t_list *undone, int **map)
{
  int		i;

  i = 1;
  if (!undone)
    return (1);
  while (i < 10)
    {
      if (undone->val[i] == 1)
	{
	  map[undone->y][undone->x] = i;
	  update(undone, map);
	  if (complete_map(undone, undone->next, map) == 1)
	    return (1);
	  map[undone->y][undone->x] = 0;
	  update(undone, map);
	}
      i++;
    }
  return (0);
}
