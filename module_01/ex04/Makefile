COMP	= c++
NAME	= sed
SRCS	= main.cpp
FLAGS	= -Wall -Wextra -Werror -std=c++98 -g3

all: $(NAME)

$(NAME): $(SRCS)
	$(COMP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
