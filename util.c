/*
** util.c for  in /home/thomas/Documents/epitech/PSU_2015_my_select
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sat Feb 27 00:45:10 2016 Thomas HENON
** Last update Sat Feb 27 01:29:56 2016 thomas
*/

#include "my_select.h"

void	move_up(t_my_select *my_select, t_linkedlist *args)
{
  if (!get_arg(args, my_select->cur_col, my_select->cur_line + 1))
    {
      if (my_select->cur_col > 0 && my_select->cur_line == 0)
	{
	  my_select->cur_col--;
	  my_select->cur_line = get_nbr_lines(args, my_select->cur_col) - 1;
	}
      else
	{
	  my_select->cur_line = 0;
	  my_select->cur_col = 0;
	}
    }
}
