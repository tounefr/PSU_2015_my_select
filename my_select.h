/*
** my_select.h for  in /home/thomas/Documents/epitech/PSU_2015_my_select
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sat Feb 27 00:44:54 2016 Thomas HENON
** Last update Sat Feb 27 01:09:07 2016 thomas
*/

#ifndef __MY_SELECT_H__
# define __MY_SELECT_H__

# include <stdlib.h>
# include <ncurses.h>
# include <unistd.h>

# define DEBUG 0

typedef struct s_arg
{
  unsigned int	col;
  unsigned int	line;
  unsigned int	index;
  unsigned char	selected;
  unsigned char	focus;
  char		*str;

}		t_arg;

typedef struct		s_linkedlist
{
  struct s_linkedlist	*next;
  void			*data;
  unsigned int		nbr_elems;
}			t_linkedlist;

typedef struct		s_my_select
{
  unsigned int		win_width;
  unsigned int		win_height;
  unsigned int		nbr_cols;
  unsigned int		cur_line;
  unsigned int		cur_col;
  unsigned int		margin;
}			t_my_select;

/*
** linkedlists.c
*/
char		push_back(t_linkedlist **head, void *data);
t_linkedlist	*new_elem(void *data);
void		free_list(t_linkedlist *head);
void		delete_elem(t_linkedlist **head, void *ptr);
t_linkedlist	*get_elem(t_linkedlist *head, int i);

/*
** my.h
*/
void		my_putchar(char c);
void		my_putstr(char *str);
unsigned int	my_strlen(char *str);

/*
** on_key.c
*/
char		on_key_up(t_my_select *my_select, t_linkedlist **args);
char		on_key_down(t_my_select *my_select, t_linkedlist **args);
char		on_key_left(t_my_select *my_select, t_linkedlist **args);
char		on_key_right(t_my_select *my_select, t_linkedlist **args);
char		on_key_backspace(t_my_select *my_select, t_linkedlist **args);
char		on_key_space(t_my_select *my_select, t_linkedlist **args);
char		on_key_enter(t_my_select *my_select, t_linkedlist **args);
char		on_key_resize(t_my_select *my_select, t_linkedlist **args);
char		on_key(t_my_select *my_select, t_linkedlist **args, int key);

/*
** main.c
*/
char	init_t_arg(t_arg **arg, char *str);
char	put_args_in_ll(int argc, char **argv, t_linkedlist **args);
char	usage(int argc);

/*
** my_select.c
*/
t_arg		*get_arg(t_linkedlist *args, unsigned int col, unsigned int line);
char		init_t_my_select(t_my_select **my_select);
void		free_my_select(t_my_select *select_, t_linkedlist **args);
void		main_loop(t_my_select *my_select, t_linkedlist **args);
char		my_select(t_linkedlist **args);

/*
** calc_pos.c
*/
unsigned int	get_nbr_lines(t_linkedlist *args, unsigned int col);
void		calc_args_positions_indexes(t_my_select *my_select,
					    t_linkedlist *args);
void		calc_args_positions(t_my_select *my_select, t_linkedlist *args);
void		test_window_too_short(t_my_select *my_select);
unsigned int	get_max_strlen_col(t_linkedlist	*args, unsigned int col);

/*
** display_args.c
*/
void		display_arg(t_my_select *my_select, t_arg *arg, unsigned int margin);
void		display_args(t_my_select *my_select, t_linkedlist *args);
void		display_if_args_removed(t_linkedlist **args);
void		display_selected_args(t_linkedlist **args);

/*
** util.c
*/
void		move_up(t_my_select *my_select, t_linkedlist *args);

#endif
