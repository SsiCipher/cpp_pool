COMP	= c++
NAME	= formExamples
FLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS	= Bureaucrat.cpp \
		  Form.cpp \
		  PresidentialPardonForm.cpp \
		  RobotomyRequestForm.cpp \
		  ShrubberyCreationForm.cpp\
		  main.cpp

all: $(NAME)

$(NAME): $(SRCS) Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
	$(COMP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
