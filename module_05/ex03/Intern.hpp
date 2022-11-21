#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern &obj);
		Intern	&operator=(const Intern &obj);

		Form	*makeForm(std::string& formName, std::string& target);
};

#endif
