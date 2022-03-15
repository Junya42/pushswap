# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anremiki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 23:53:14 by anremiki          #+#    #+#              #
#    Updated: 2022/03/15 07:22:31 by anremiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c	\
		lstutils.c	\
		free.c	\
		lst.c	\
		miniprintf.c	\
		push.c	\
		revrotate.c	\
		rotate.c	\
		swap.c	\
		utils.c	\
		utils2.c	\
		colors.c	\
		algo.c	\
		algo_utils.c	\
		algo_moves.c	\

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
