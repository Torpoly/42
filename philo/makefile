# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpol <rpol@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 14:17:45 by rpol              #+#    #+#              #
#    Updated: 2022/02/21 14:10:19 by rpol             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

NAME = philo
SRCS_NAME = philo.c
SRCS_PATH = srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
INCS_NAME = philo.h
INCS_PATH = includes
INCS = $(addprefix $(INCS_PATH)/, $(INCS_NAME))
RM = rm -rf
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
			${CC} ${CFLAGS} -g -I ${INCS_PATH} -c $< -o $@

${NAME}:	${OBJS} ${INCS}
			${CC} -g -o ${NAME} ${OBJS} 
clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY : all clean fclean re