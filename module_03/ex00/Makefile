COMP	= c++
NAME	= clapTrap
SRCS	= ClapTrap.cpp
FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS) ClapTrap.hpp
	$(COMP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
