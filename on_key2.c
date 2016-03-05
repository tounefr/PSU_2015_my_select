/*
** on_key2.c for  in /home/thomas/Documents/epitech/PSU_2015_my_select
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sat Feb 27 00:45:00 2016 Thomas HENON
** Last update Sat Feb 27 01:03:02 2016 thomas
*/

#include "my_select.h"

char		on_key_space(t_my_select *my_select, t_linkedlist **args)
{
  t_arg		*arg;
  t_linkedlist	*tmp;
  char		selected;

  selected = 0;
  tmp = *args;
  while (tmp)
    {
      arg = (t_arg*)tmp->data;
      if (arg->col == my_select->cur_col && arg->line == my_select->cur_line)
	{
	  if (arg->selected)
	    arg->selected = 0;
	  else
	    {
	      arg->selected = 1;
	      selected = 1;
	    }
	}
      tmp = tmp->next;
    }
  if (selected)
    on_key_down(my_select, args);
  return (1);
}

char	on_key_enter(t_my_select *my_select, t_linkedlist **args)
{
  return (0);
}

char	on_key_resize(t_my_select *my_select, t_linkedlist **args)
{
  clear();
  calc_args_positions(my_select, *args);
  display_args(my_select, *args);
  return (1);
}

char		on_key_escape(t_my_select *my_select, t_linkedlist **args)
{
  t_linkedlist	*tmp;
  t_arg		*arg;

  tmp = *args;
  while (tmp)
    {
      arg = (t_arg*)tmp->data;
      if (arg->selected)
	arg->selected = 0;
      tmp = tmp->next;
    }
  return (0);
}

char	on_key(t_my_select *my_select, t_linkedlist **args, int key)
{
  if (key == KEY_UP && !on_key_up(my_select, args))
    return (0);
  else if (key == KEY_DOWN && !on_key_down(my_select, args))
    return (0);
  else if (key == KEY_LEFT && !on_key_left(my_select, args))
    return (0);
  else if (key == KEY_RIGHT && !on_key_right(my_select, args))
    return (0);
  else if (key == ' ' && !on_key_space(my_select, args))
    return (0);
  else if (key == '\n' && !on_key_enter(my_select, args))
    return (0);
  else if ((key == KEY_BACKSPACE || key == KEY_DC) &&
	   !on_key_backspace(my_select, args))
    return (0);
  else if (key == 27 && !on_key_escape(my_select, args))
    return (0);
  else if (key == KEY_RESIZE && !on_key_resize(my_select, args))
    return (0);
  return (1);
}
