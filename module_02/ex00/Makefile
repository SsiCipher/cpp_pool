COMP	= c++
NAME	= fixed
SRCS	= Fixed.cpp main.cpp
FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS) Fixed.hpp
	$(COMP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
