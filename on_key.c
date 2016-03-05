/*
** on_key.c for  in /home/thomas/Documents/epitech/PSU_2015_my_select
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sat Feb 27 00:45:05 2016 Thomas HENON
** Last update Sat Feb 27 01:31:22 2016 thomas
*/

#include "my_select.h"

char		on_key_up(t_my_select *my_select, t_linkedlist **args)
{
  unsigned int	nbr_lines;

  if (my_select->cur_line > 0)
    my_select->cur_line--;
  else if (my_select->cur_line == 0 && my_select->cur_col > 0)
    {
      my_select->cur_col--;
      nbr_lines = get_nbr_lines(*args, my_select->cur_col);
      my_select->cur_line = nbr_lines - 1;
    }
  else if (my_select->cur_line == 0 && my_select->cur_line == 0)
    {
      my_select->cur_col = my_select->nbr_cols - 1;
      my_select->cur_line = get_nbr_lines(*args, my_select->cur_col) - 1;
    }
  return (1);
}

char		on_key_down(t_my_select *my_select, t_linkedlist **args)
{
  unsigned int	nbr_lines;

  nbr_lines = get_nbr_lines(*args, my_select->cur_col);
  if (my_select->cur_line < (nbr_lines - 1))
    my_select->cur_line++;
  else if (my_select->cur_line == (nbr_lines - 1) &&
	   my_select->cur_col < (my_select->nbr_cols - 1))
    {
      my_select->cur_col++;
      my_select->cur_line = 0;
    }
  else if (my_select->cur_col == (my_select->nbr_cols - 1))
    {
      if (my_select->cur_line == (get_nbr_lines(*args, my_select->cur_col) - 1))
	{
	  my_select->cur_col = 0;
	  my_select->cur_line = 0;
	}
    }
  return (1);
}

char	on_key_left(t_my_select *my_select, t_linkedlist **args)
{
  int	col;

  if (my_select->cur_col > 0)
    my_select->cur_col--;
  else if (my_select->cur_col == 0)
    {
      col = my_select->nbr_cols - 1;
      while (!get_arg(*args, col, my_select->cur_line) && col > 0)
	col--;
      my_select->cur_col = col;
    }
  return (1);
}

char	on_key_right(t_my_select *my_select, t_linkedlist **args)
{
  int	col;

  if (my_select->cur_col < (my_select->nbr_cols - 1))
    {
      col = my_select->cur_col + 1;
      my_select->cur_col = 0;
      if (!get_arg(*args, col, my_select->cur_line))
	col++;
      else
	my_select->cur_col = col;
    }
  else if (my_select->cur_col == (my_select->nbr_cols - 1))
    my_select->cur_col = 0;
  return (1);
}

char	on_key_backspace(t_my_select *my_select, t_linkedlist **args)
{
  t_arg	*arg;

  if (!(arg = get_arg(*args, my_select->cur_col, my_select->cur_line)))
    return (0);
  delete_elem(args, arg);
  if (*args == NULL)
    return (0);
  move_up(my_select, *args);
  return (1);
}
