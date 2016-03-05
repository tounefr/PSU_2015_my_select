##
## Makefile for  in /home/thomas/Documents/epitech/PSU_2015_my_select
##
## Made by Thomas HENON
## Login   <thomas.henon@epitech.net>
##
## Started on  Mon Feb 15 20:11:40 2016 Thomas HENON
## Last update Sat Feb 27 01:03:52 2016 Thomas HENON
##

NAME	= my_select

RM	= rm -f

CC	= gcc

CFLAGS	= -lncurses

SRCS	=	main.c \
		linkedlists.c \
	  	my_select.c \
	 	my.c \
		on_key.c \
		on_key2.c \
		calc_pos.c \
		display_args.c \
		util.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
