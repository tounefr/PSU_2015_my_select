/*
** my_select.c for  in /home/thomas/Documents/epitech/PSU_2015_my_select
** 
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
** 
** Started on  Sat Feb 27 00:44:47 2016 Thomas HENON
** Last update Sat Feb 27 00:45:29 2016 Thomas HENON
*/

#include "my_select.h"

t_arg	*get_arg(t_linkedlist *args, unsigned int col, unsigned int line)
{
  t_arg	*arg;

  while (args)
    {
      arg = (t_arg*)args->data;
      if (arg->col == col && arg->line == line)
	return (arg);
      args = args->next;
    }
  return (NULL);
}

char	init_t_my_select(t_my_select **my_select)
{
  if (NULL == (*my_select = malloc(sizeof(t_my_select))))
    return (0);
  (*my_select)->win_width = 0;
  (*my_select)->win_height = 0;
  (*my_select)->nbr_cols = 0;
  (*my_select)->margin = 0;
  (*my_select)->cur_col = 0;
  (*my_select)->cur_line = 0;
  return (1);
}

void	free_my_select(t_my_select *select_, t_linkedlist **args)
{
  free(select_);
  free_list(*args);
}

void		main_loop(t_my_select *my_select, t_linkedlist **args)
{
  int		key;
  char		stop;

  stop = 0;
  while (!stop)
    {
      calc_args_positions(my_select, *args);
      display_args(my_select, *args);
      key = getch();
      if (!on_key(my_select, args, key))
	stop = 1;
      clear();
    }
}

char		my_select(t_linkedlist **args)
{
  t_my_select	*my_select;

  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
  move(0, 0);
  if (!init_t_my_select(&my_select))
    return (0);
  main_loop(my_select, args);
  endwin();
  display_selected_args(args);
  display_if_args_removed(args);
  free_my_select(my_select, args);
  return (1);
}
