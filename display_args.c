/*
** display_args.c for  in /home/thomas/Documents/epitech/PSU_2015_my_select
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sat Feb 27 00:44:14 2016 Thomas HENON
** Last update Sat Feb 27 01:09:16 2016 thomas
*/

#include "my_select.h"

void	display_arg(t_my_select *my_select, t_arg *arg, unsigned int margin)
{
  if (arg->line == my_select->cur_line && arg->col == my_select->cur_col)
    attron(A_UNDERLINE);
  if (arg->selected)
    attron(A_REVERSE);
  mvprintw(arg->line, arg->col + margin, arg->str);
  if (arg->selected)
    attroff(A_REVERSE);
  if (arg->line == my_select->cur_line && arg->col == my_select->cur_col)
    attroff(A_UNDERLINE);
}

void		display_args(t_my_select *my_select, t_linkedlist *args)
{
  unsigned int	col;
  unsigned int	line;
  unsigned int	col_len;
  unsigned int	nbr_lines;
  t_arg		*arg;

  col = 0;
  while (col < my_select->nbr_cols)
    {
      nbr_lines = get_nbr_lines(args, col);
      col_len = get_max_strlen_col(args, col);
      line = 0;
      while (line < nbr_lines)
	{
	  arg = get_arg(args, col, line);
	  display_arg(my_select, arg, my_select->margin);
	  line++;
	}
      my_select->margin += col_len;
      col++;
    }
  test_window_too_short(my_select);
  if (DEBUG)
    mvprintw(my_select->win_height-1, my_select->win_width-50, "col %d line %d",
	   my_select->cur_col, my_select->cur_line);
}

void	display_if_args_removed(t_linkedlist **args)
{
  if (*args == NULL)
    my_putstr("Tous les éléments ont été supprimés !\n");
}

void		display_selected_args(t_linkedlist **args)
{
  t_linkedlist	*selected_args;
  t_arg		*arg;
  t_linkedlist	*tmp;

  tmp = *args;
  selected_args = NULL;
  while (tmp)
    {
      arg = (t_arg*)tmp->data;
      if (arg->selected)
	push_back(&selected_args, (void*)tmp->data);
      tmp = tmp->next;
    }
  tmp = selected_args;
  while (selected_args)
    {
      arg = (t_arg*)selected_args->data;
      my_putstr(arg->str);
      if (selected_args->next)
	my_putchar(' ');
      selected_args = selected_args->next;
    }
  free_list(tmp);
}
