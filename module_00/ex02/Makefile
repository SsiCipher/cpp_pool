COMP	= g++
NAME	= account
FLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS	= main.cpp Account.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(COMP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
