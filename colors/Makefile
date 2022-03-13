# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anremiki <anremiki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 15:36:33 by anremiki          #+#    #+#              #
#    Updated: 2021/10/19 03:50:00 by anremiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	./srcs/ft_colors.c ./srcs/ft_putstr.c
		
INCLUDES		=	./includes/

OBJS			= $(SRCS:.c=.o)


CC				= gcc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror -I $(INCLUDES)

NAME			= libcolor.a


all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(OBONUS)

fclean:			clean
				$(RM) $(NAME) $(OBONUS)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
