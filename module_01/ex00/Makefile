COMP	= c++
NAME	= zombie
SRCS	= Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
FLAGS	= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS) Zombie.hpp
	$(COMP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
