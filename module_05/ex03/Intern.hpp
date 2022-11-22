#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	class InternException: public std::exception
	{
		public:
			const char *what() const throw ();
	};

	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern &obj);
		Intern	&operator=(const Intern &obj);

		Form	*makeForm(const std::string& formName, const std::string& target);
};

#endif
