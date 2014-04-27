/*
** sud_main.c for sudoku in /u/all/kim_r/cu/public/Grp/Sudoku/refait
**
** Made by richard kim
** Login   <kim_r@epitech.net>
**
** Started on  Sat Apr 24 11:45:47 2010 richard kim
** Last update Sun Apr 25 22:24:12 2010 damien locque
*/

#include	"sudo.h"

void		free_list(t_list *list)
{
  t_list	*tmp;

  if (list)
    while (list)
      {
	free(list->val);
	tmp = list;
	free(tmp);
	list = list->next;
      }
}

t_square	*add_map(t_square *list, int **map)
{
  t_square	*new;
  t_square	*temp;

  new = xmalloc(sizeof(t_list));
  new->map = map;
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

void		aff_and_free(t_square *sq)
{
  int		loop;
  t_square	*tmp;

  loop = 0;
  while (sq != NULL)
    {
      if (loop)
	my_putstr("####################\n");
      aff_tab(sq->map);
      free_tab(sq->map);
      tmp = sq;
      sq = sq->next;
      free(tmp);
      loop++;
    }
}

int		main()
{
  char		*s;
  int		**tab;
  t_square	*sq;
  t_list	*undone;

  sq = NULL;
  while (s = get_next_line(0))
    {
      undone = NULL;
      free(s);
      tab = malloc_tab(tab);
      tab = get_map(tab);
      sq = add_map(sq, tab);
      undone = algo_init(tab, undone);
      update(undone, tab);
      /*      algo_low(tab, undone);*/
      complete_map(undone, undone, tab);
      free_list(undone);
    }
  aff_and_free(sq);
  return (0);
}
