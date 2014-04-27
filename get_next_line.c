/*
** get_next_line.c for get nxt in /u/all/locque_d/cu/rendu/lem-in
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Mon Apr 12 12:43:06 2010 damien locque
** Last update Sat Apr 24 13:10:27 2010 richard kim
*/


#include "sudo.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static char	*fill_str(char *str, int i, char *buffer, int *begin)
{
  char		*new_str;
  int		prev_length;

  prev_length = (str != NULL) ? strlen(str) : 0;
  new_str = xmalloc(prev_length + i + 1);
  if (str != NULL)
    strncpy(new_str, str, prev_length);
  strncpy(&new_str[prev_length], &buffer[*begin], i);
  new_str[prev_length + i] = '\0';
  *begin += i + 1;
  free(str);
  return (new_str);
}

char		*get_next_line(const int fd)
{
  char		*str;
  int		i;
  static char	buffer[BUFF_SIZE];
  static int	begin = 0;
  static int	buff_length = 0;

  str = NULL;
  i = 0;
  while (TRUE)
    {
      if (begin >= buff_length)
	{
	  if ((buff_length = xread(fd, buffer, BUFF_SIZE)) == 0)
	    return (str);
	  i = 0;
	  begin = 0;
	}
      if (buffer[begin + i] == '\n')
	return ((str = fill_str(str, i, buffer, &begin)));
      if (begin + i == buff_length - 1)
	str = fill_str(str, 1 + i, buffer, &begin);
      i++;
    }
}
