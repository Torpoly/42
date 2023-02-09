CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ScavTrap

SRCS =	ClapTrap.cpp \
		ScavTrap.cpp \
		main.cpp 

OBJ_DIR = obj

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	rmdir $(OBJ_DIR) || true

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re