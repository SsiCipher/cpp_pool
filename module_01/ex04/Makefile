COMP	= c++
NAME	= violence
SRCS	= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	$(COMP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
