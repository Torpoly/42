CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP

NAME = Bureaucrats_and_Types_AForms

SRCS =	Bureaucrat.cpp \
		PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp \
		AForm.cpp \
		main.cpp 

OBJ_DIR = obj

DEPS_FILES = Bureaucrat.hpp \
			 PresidentialPardonForm.hpp \
			 RobotomyRequestForm.hpp \
			 ShrubberyCreationForm.hpp \
			 AForm.hpp

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

DEPS = $(addprefix $(OBJ_DIR)/, $(DEPS_FILES:.hpp=.d))

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:

	rm -rf $(OBJ_DIR)
	if [ -n "$(shell find . -name '*_shrubbery' -print -quit)" ]; then $(RM) *_shrubbery; fi

fclean: clean
	$(RM) $(NAME)


re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re