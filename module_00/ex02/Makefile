COMP	= c++
NAME	= account
FLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS	= tests.cpp Account.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(COMP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
