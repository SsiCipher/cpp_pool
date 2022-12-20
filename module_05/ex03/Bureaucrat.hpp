#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned short		_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, unsigned short grade);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);

		const std::string	getName(void) const;
		unsigned short		getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(const Form &form);
		void				executeForm(Form const &form);

		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw ();
		};

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw ();
		};
};

std::ostream &operator<< (std::ostream &out, const Bureaucrat &c);

#endif
