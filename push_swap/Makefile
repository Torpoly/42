# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpol <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 23:50:02 by rpol              #+#    #+#              #
#    Updated: 2022/01/19 00:13:47 by rpol             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_parsing.c ft_push_swap.c ft_split_ps.c utils1.c utils2.c \
      ft_simplify.c ft_linkinit.c ft_startsort.c ft_swap.c ft_sort.c 

OBJ = ${SRC:.c=.o}

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = push_swap

all: ${NAME}

${NAME} : ${OBJ}
	${CC} ${FLAGS} ${OBJ} push_swap.h -o ${NAME} 

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
