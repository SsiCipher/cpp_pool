COMP	= c++
NAME	= phonebook
FLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS	= Contact.cpp PhoneBook.cpp main.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(COMP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
