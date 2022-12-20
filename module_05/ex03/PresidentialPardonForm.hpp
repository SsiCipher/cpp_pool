#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm: public Form
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);

		void		execute(Bureaucrat const & executor) const;
};

#endif
