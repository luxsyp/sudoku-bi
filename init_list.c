/*
** algo_init.c for sudoku in /u/all/kim_r/cu/public/Grp/Sudoku
**
** Made by richard kim
** Login   <kim_r@epitech.net>
**
** Started on  Fri Apr 23 23:16:37 2010 richard kim
** Last update Sun Apr 25 21:51:51 2010 richard kim
*/

#include	"sudo.h"

t_list		*end_add(t_list *list, int x, int y)
{
  t_list	*new;
  t_list	*temp;

  new = xmalloc(sizeof(t_list));
  new->val = xmalloc(10 * sizeof(*(new->val)));
  new->x = x;
  new->y = y;
  new->next = NULL;
  if (list == NULL)
    return (new);
  else
    {
      temp = list;
      while (temp->next != NULL)
	temp = temp->next;
      temp->next = new;
      return (list);
    }
}

t_list		*sort_list(t_list *undone)
{
  int		nb;
  int		n;

  nb = 1;
  n = 0;
  while (nb < 10)
    {

      nb++;
    }
  return (undone);
}

t_list		*algo_init(int **tab, t_list *undone)
{
  int		x;
  int		y;
  t_list	*last;

  y = 0;
  while (y < 9)
    {
      x = 0;
      while (x < 9)
	{
	  if (tab[y][x] == 0)
	    undone = end_add(undone, x, y);
	  x++;
	}
      y++;
    }
  return (undone);
}
