#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	class LowException: public std::exception
	{
		public:
			const char *what() const throw ();
	};

	class HighException: public std::exception
	{
		public:
			const char *what() const throw ();
	};

	protected:
		const std::string		_name;
		bool					_isSigned;
		const unsigned short	_gradeToSign;
		const unsigned short	_gradeToExec;
		LowException			GradeTooLowException;
		HighException			GradeTooHighException;

	public:
		Form(void);
		Form(const std::string name, const unsigned short gradeToSign,
			const unsigned short gradeToExec);
		~Form(void);
		Form(const Form &obj);
		Form &operator=(const Form &obj);

		std::string			getName(void) const;
		bool				getIsSigned(void) const;
		unsigned short		getGradeToSign(void) const;
		unsigned short		getGradeToExec(void) const;

		void				beSigned(const Bureaucrat &him);
		virtual void		execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<< (std::ostream &stream, const Form &obj);

#endif