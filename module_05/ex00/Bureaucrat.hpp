#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		std::string		name;
		unsigned short	grade;
		std::exception	GradeTooLowException;
		std::exception	GradeTooHighException;

	public:
		Bureaucrat(const std::string name, unsigned short grade);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);



		std::string		getName(void);
		unsigned short	getGrade(void);
		void			incrementGrade(void);
		void			decrementGrade(void);
};

#endif
