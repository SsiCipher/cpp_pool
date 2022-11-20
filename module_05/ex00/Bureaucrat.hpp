#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>


class Bureaucrat
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

	private:
		const std::string	name;
		unsigned short		grade;
		LowException		GradeTooLowException;
		HighException		GradeTooHighException;

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
};

std::ostream &operator<< (std::ostream &out, const Bureaucrat &c);

#endif