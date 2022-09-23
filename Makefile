# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 19:56:37 by jlenna            #+#    #+#              #
#    Updated: 2022/03/26 20:27:06 by jlenna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRCS = push_swap.c	ft_valid.c pa_pb.c\
		rra_rrb.c 	ra_rb.c 		sa_sb.c\
		parser.c	create_list.c 	simple_a.c\
		sorting.c 	sorting1.c 	sorting2.c\
		sorting3.c\

SRCS_BONUS = ft_valid.c pa_pb.c\
		rra_rrb.c 	ra_rb.c 		sa_sb.c\
		parser.c	create_list.c 	simple_a.c\
		sorting.c 	sorting1.c 	sorting2.c\
		sorting3.c checker.c 	get_next_line.c\
		get_next_line_utils.c
		
HEADER = push_swap.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIB = libft/libft.a

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

all:	libft $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS)  -c $< -o $@

libft: 
	make -C libft/

$(NAME) : 	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

bonus: libft $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB) -o $(NAME_BONUS)

clean :
	make -C libft/ clean
	$(RM) $(OBJS) $(OBJS_BONUS)
	
fclean : clean
	make -C libft/ fclean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re libft bonus