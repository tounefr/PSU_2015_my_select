/*
** main.c for  in /home/thomas/Documents/epitech/PSU_2015_my_select
**
** Made by Thomas HENON
** Login   <thomas.henon@epitech.net>
**
** Started on  Sat Feb 27 00:44:23 2016 Thomas HENON
** Last update Sat Feb 27 01:04:41 2016 thomas
*/

#include "my_select.h"

char	init_t_arg(t_arg **arg, char *str)
{
  if (NULL == (*arg = malloc(sizeof(t_arg))))
    return (0);
  (*arg)->col = 0;
  (*arg)->line = 0;
  (*arg)->index = 0;
  (*arg)->selected = 0;
  (*arg)->focus = 0;
  (*arg)->str = (str);
  return (1);
}

char	put_args_in_ll(int argc, char **argv, t_linkedlist **args)
{
  int	i;
  t_arg	*arg;

  i = 1;
  while (i < argc)
    {
      if (!init_t_arg(&arg, argv[i]))
	return (0);
      push_back(args, arg);
      i++;
    }
  return (1);
}

char	usage(int argc)
{
  if (argc == 1)
    {
      my_putstr("Usage: ./my_select arg1,arg2,argN,...\n");
      return (0);
    }
  return (1);
}

int		main(int argc, char **argv)
{
  t_linkedlist	*args;

  args = NULL;
  if (!usage(argc))
    return (1);
  if (!put_args_in_ll(argc, argv, &args))
    return (1);
  if (!my_select(&args))
    return (1);
  return (0);
}
