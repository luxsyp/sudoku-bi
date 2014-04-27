/*
** my_getnbr.c for ek f in /u/all/locque_d/cu/rendu/c/minitalk
**
** Made by damien locque
** Login   <locque_d@epitech.net>
**
** Started on  Sat Mar 13 16:15:23 2010 damien locque
** Last update Fri Apr 23 20:09:54 2010 damien locque
*/

#include "sudo.h"

int		my_getnbr(char *str)
{
  int		res;

  if (*str == '-')
    return (-my_getnbr(str + 1));
  if (*str == '+')
    return (my_getnbr(str + 1));
  res = 0;
  while (*str)
    {
      res *= 10;
      res += *str - '0';
      str++;
    }
  return (res);
}
