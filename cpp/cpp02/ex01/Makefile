COMPILER = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = canon

SRCS =	Fixed.cpp\
		main.cpp 

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re