/*
** lem-in.h for lem\ in /u/all/locque_d/cu/rendu/c/lem-in
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Mon Apr 12 14:46:11 2010 damien locque
** Last update Sun Apr 25 22:05:43 2010 damien locque
*/

#ifndef		_MY_SUDO_H_
# define	_MY_SUDO_H_

# include	<stdlib.h>
# define	FALSE 0
# define	TRUE 1
# define	BUFF_SIZE 512

typedef struct	s_list
{
  int		x;
  int		y;
  char		*val;
  struct s_list	*next;
}		t_list;

typedef struct	s_square
{
  int		**map;
  struct s_square *next;
}		t_square;

/* init_list.c */
t_list		*algo_init(int **tab, t_list *undone);
t_list		*end_add(t_list *list, int x, int y);


/* algo_low.c */
/*void		check_low(int **tab, t_list *undone);
int		algo_low(int **tab, t_list *begin);
*/
/* algo */
int		complete_map(t_list *begin, t_list *undone, int **map);
void		update(t_list *undone, int **map);
int		check_line_col(int nb, int **map, int y, int x);
int		check_square(int nb, int **map, int x, int y);

/* gnl */
char		*get_next_line(const int fd);
static char	*fill_str(char *str, int i,
			  char *buffer, int *begin);

/* map func */
int		**malloc_tab(int **tab);
int		**get_map(int **tab);
void		aff_tab(int **tab);
void		free_tab(int **tab);

/* usual func */
int		my_getnbr(char *str);
void		my_putnbr(int nb);
void		my_putchar(char c);
void		my_putstr(char *str);
void		my_puterror(char *str);
int		my_strlen(char *str);

/* xfunc */
void		*xmalloc(size_t size);
size_t		xread(int fd, char *buff, size_t count);
size_t		xwrite(int fd, void *buff, size_t nbytes);

#endif		/* !_MY_SUDO_H_ */
