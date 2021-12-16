# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpol <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 02:20:09 by rpol              #+#    #+#              #
#    Updated: 2021/12/06 05:24:57 by rpol             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_putnbr.c
OBJ = ${SRC:.c=.o}

CC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar -cr

RM = rm -f

NAME = libftprintf.a

all: ${NAME}

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${AR}  ${NAME} ${OBJ}

clean:
		${RM} ${OBJ}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
