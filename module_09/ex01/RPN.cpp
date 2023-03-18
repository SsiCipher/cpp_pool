#include "RPN.hpp"

RPN::RPN(void)
{
	std::cout << "[RPN] Default constructor has been called!" << std::endl;
}

RPN::~RPN()
{
	std::cout << "[RPN] Destructor has been called!" << std::endl;
}

RPN::RPN(const RPN &obj)
{
	std::cout << "[RPN] Copy constructor has been called!" << std::endl;
	*this = obj;
}

RPN &RPN::operator=(const RPN &obj)
{
	std::cout << "[RPN] Copy assignment operator has been called!" << std::endl;
	if (this != &obj)
	{
	}
	return (*this);
}
