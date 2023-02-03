COMPILER = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = sed_is_for_losers

SRCS =	main.cpp 

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