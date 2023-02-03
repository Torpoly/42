COMPILER = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = violence

SRCS =	main.cpp   \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp \

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