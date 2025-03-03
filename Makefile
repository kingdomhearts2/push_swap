# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edjebri <edjebri@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 20:47:43 by edjebri           #+#    #+#              #
#    Updated: 2025/03/04 00:23:32 by edjebri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =	cost.c\
		stack_utils.c\
		init_stack.c\
		error.c\
		prep_for_push.c\
		push_rotateboth.c\
		push_swap.c\
		rotate_2.c\
		rotate.c\
		sort_three.c\
		swap.c\

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	cc -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
