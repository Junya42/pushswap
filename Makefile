# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anremiki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 23:53:14 by anremiki          #+#    #+#              #
#    Updated: 2022/03/22 21:02:43 by anremiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/main.c	\
		srcs/lstutils.c	\
		srcs/free.c	\
		srcs/lst.c	\
		srcs/miniprintf.c	\
		srcs/push.c	\
		srcs/revrotate.c	\
		srcs/rotate.c	\
		srcs/swap.c	\
		srcs/utils.c	\
		srcs/utils2.c	\
		srcs/colors.c	\
		srcs/algo.c	\
		srcs/algo_utils.c	\
		srcs/algo_moves.c	\
		srcs/algo_three.c	\
		srcs/algo_five.c	\

OBJS = ${SRCS:.c=.o}

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

PRINT = 0

NAME = push_swap

ifdef WITH_PRINT
PRINT = 1
endif


.c.o:
	${CC} -I includes ${CFLAGS} -g3 -D PRINT=$(PRINT) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C ./libft
	make -C ./ft_printf
	$(CC) $(CFLAGS) -D PRINT=$(PRINT) -g3 $(OBJS) ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)

debug: $(OBJS)
	make bonus -C ./libft
	make -C ./ft_printf
	$(CC) $(CFLAGS) -D PRINT=$(PRINT) -g3 $(OBJS) ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)

p: fclean
	$(MAKE) WITH_PRINT=1

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: clean
