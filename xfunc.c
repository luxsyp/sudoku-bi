/*
** xfunc.c for Sudoku in /u/all/kim_r/cu/public/Grp/Sudoku
**
** Made by richard kim
** Login   <kim_r@epitech.net>
**
** Started on  Sat Apr 24 02:26:05 2010 richard kim
** Last update Sat Apr 24 02:30:38 2010 richard kim
*/

#include	<unistd.h>
#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"sudo.h"

void		*xmalloc(size_t size)
{
  void		*str;

  if (!(str = malloc(size)))
    {
      my_puterror("Memory allocation failure - Exit\n");
      exit(EXIT_FAILURE);
    }
  return (str);
}

size_t		xread(int fd, char *buff, size_t count)
{
  int		nb_read;

  if ((nb_read = read(fd, buff, count)) == -1)
    {
      my_puterror("Read fail\n");
      exit(EXIT_FAILURE);
    }
  return ((size_t)nb_read);
}

size_t		xwrite(int fd, void *buff, size_t nbytes)
{
  int		nb_read;

  if ((nb_read = write(fd, buff, nbytes)) == -1)
    my_puterror("Can't write\n");
  return ((size_t)nb_read);
}
