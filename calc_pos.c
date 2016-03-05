/*
** calc_pos.c for  in /home/thomas/Documents/epitech/PSU_2015_my_select
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sat Feb 27 00:44:10 2016 Thomas HENON
** Last update Sat Feb 27 01:08:06 2016 thomas
*/

#include "my_select.h"

unsigned int	get_nbr_lines(t_linkedlist *args, unsigned int col)
{
  unsigned int	lines;
  t_arg		*arg;

  lines = 0;
  while (args)
    {
      arg = (t_arg*)args->data;
      if (arg->col == col)
	lines++;
      args = args->next;
    }
  return (lines);
}

void	calc_args_positions_indexes(t_my_select *my_select, t_linkedlist *args)
{
  t_arg	*arg;
  int	i;

  my_select->margin = 0;
  i = 0;
  while (args)
    {
      arg = (t_arg*)args->data;
      arg->index = i;
      arg->col = i / my_select->win_height;
      arg->line = i % my_select->win_height;
      args = args->next;
      i++;
    }
  my_select->nbr_cols = arg->col + 1;
}

void		test_window_too_short(t_my_select *my_select)
{
  if (my_select->margin > my_select->win_width)
    {
      clear();
      mvprintw(0, 0, "Fenetre trop petite, veuillez la redimmensionner");
    }
}

void	calc_args_positions(t_my_select *my_select, t_linkedlist *args)
{
  getmaxyx(stdscr, my_select->win_height, my_select->win_width);
  calc_args_positions_indexes(my_select, args);
}

unsigned int	get_max_strlen_col(t_linkedlist	*args, unsigned int col)
{
  t_arg		*arg;
  unsigned int	max;

  max = 0;
  while (args)
    {
      arg = (t_arg*)args->data;
      if (arg->col == col && my_strlen(arg->str) > max)
	max = my_strlen(arg->str);
      args = args->next;
    }
  return (max);
}
