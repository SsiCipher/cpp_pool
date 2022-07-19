COMP	= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS	= megaphone.cpp
NAME	= megaphone

all: $(NAME)

$(NAME): $(SRCS)
	$(COMP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
