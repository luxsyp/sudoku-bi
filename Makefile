##
## Makefile for here in /u/all/locque_d/cu/public/TO_RUSH_HOUR/quarante2SH
##
## Made by damien locque
## Login   <locque_d@epitech.net>
##
## Started on  Wed Mar 31 11:42:17 2010 damien locque
## Last update Sun Apr 25 22:26:56 2010 damien locque
##

NAME	= sudoki-bi

SRCS	= main.c		\
	  init_list.c		\
	  get_map.c		\
	  algo_high.c		\
	  get_next_line.c	\
	  my_getnbr.c		\
	  usual_func.c		\
	  xfunc.c

OBJS	= $(SRCS:.c=.o)
CC	= gcc -g3
CP	= cp
INC	= -I./include/
CFLAGS	+= -W -Wextra -ansi -pedantic -O3
RM	= rm -f

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(INC)
	$(CP) $(NAME) ./bin/

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)
	$(RM) ./bin/$(NAME)

re	: fclean all

.c.o	:
	$(CC) -c $(INC) -o $@ $<