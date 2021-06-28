NAME = bureaucrat

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp
OBJ = $(SRC:.cpp=.o)

%.o : %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $@

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re