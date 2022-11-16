#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class LowException: public std::exception
{
    public:
		const char *what() const throw ()
		{
        	return "The given grade is too low";
    	}
};

class HighException: public std::exception
{
    public:
		const char *what() const throw ()
		{
        	return "The given grade is too high";
    	}
};

class Bureaucrat
{
	private:
		std::string		name;
		unsigned short	grade;
		LowException	GradeTooLowException;
		HighException	GradeTooHighException;

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
