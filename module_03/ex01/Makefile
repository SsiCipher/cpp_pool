COMP	= c++
NAME	= scavTrap
SRCS	= ClapTrap.cpp ScavTrap.cpp main.cpp
FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS) ClapTrap.hpp ScavTrap.hpp
	$(COMP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
