/*
** my.c for  in /home/thomas/Documents/epitech/PSU_2015_my_select
** 
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
** 
** Started on  Sat Feb 27 00:44:31 2016 Thomas HENON
** Last update Sat Feb 27 00:44:31 2016 Thomas HENON
*/

#include "my_select.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    my_putchar(str[i++]);
}

unsigned int	my_strlen(char *str)
{
  unsigned int	i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}
