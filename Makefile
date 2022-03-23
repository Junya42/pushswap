# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anremiki <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/12 23:53:14 by anremiki          #+#    #+#              #
#    Updated: 2022/03/23 02:10:13 by anremiki         ###   ########.fr        #
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

SRCSBONUS = get_next_line/get_next_line.c	\
			get_next_line/get_next_line_utils.c	\
			bonus/main_bonus.c	\
			bonus/algo_utils_bonus.c	\
			bonus/lstutils_bonus.c	\
			bonus/free_bonus.c	\
			bonus/lst_bonus.c	\
			bonus/miniprintf_bonus.c	\
			bonus/push_bonus.c	\
			bonus/revrotate_bonus.c	\
			bonus/rotate_bonus.c	\
			bonus/swap_bonus.c	\
			bonus/utils_bonus.c	\
			bonus/utils2_bonus.c	\
			bonus/colors_bonus.c	\
			bonus/input_bonus.c	\
			bonus/input_utils_bonus.c	\


OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${SRCSBONUS:.c=.o}

RM = rm -rf

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

NAME = push_swap

NAMEBONUS = checker

.c.o: 
	${CC} -I includes ${CFLAGS} -g3 -D BUFFER_SIZE=1 -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C ./libft
	make -C ./ft_printf
	$(CC) $(CFLAGS) -g3 $(OBJS) ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)

$(NAMEBONUS): $(OBJSBONUS)
	make bonus -C ./libft
	make -C ./ft_printf
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1 -g3 $(OBJSBONUS) ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAMEBONUS)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAMEBONUS)

re: fclean all

bonus: $(NAMEBONUS)

.PHONY: all clean fclean re
.SILENT: clean fclean
