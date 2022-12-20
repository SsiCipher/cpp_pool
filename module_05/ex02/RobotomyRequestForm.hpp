#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);

		void		execute(Bureaucrat const& executor) const;
};

#endif
