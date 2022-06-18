# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpol <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 14:17:45 by rpol              #+#    #+#              #
#    Updated: 2022/06/18 23:45:19 by rpol             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread	
NAME = philo
SRCS_NAME = philo.c parsing.c linkinit.c routine.c
SRCS_PATH = srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
INCS_NAME = philo.h
INCS_PATH = includes
INCS = $(addprefix $(INCS_PATH)/, $(INCS_NAME))
RM = rm -rf
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
			${CC} ${CFLAGS} -g -I${INCS_PATH} -c $< -o $@

${NAME}:	${OBJS} ${INCS}
			${CC} -g -o ${NAME} ${OBJS} 
clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY : all clean fclean re