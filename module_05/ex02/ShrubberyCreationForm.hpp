#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);

		void		execute(Bureaucrat const & executor) const;
};

#endif
