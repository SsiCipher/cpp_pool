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
		const std::string		name;
		unsigned short	grade;
		LowException	GradeTooLowException;
		HighException	GradeTooHighException;

	public:
		Bureaucrat(const std::string name, unsigned short grade);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);

		const std::string		getName(void) const;
		unsigned short			getGrade(void) const;
		void					incrementGrade(void);
		void					decrementGrade(void);
};

std::ostream &operator<< (std::ostream &out, const Bureaucrat &c);

#endif
