COMP	= c++
NAME	= rpn
SRCS	= main.cpp RPN.cpp
FLAGS	= -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

all: $(NAME)

$(NAME): $(SRCS) RPN.hpp
	$(COMP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
