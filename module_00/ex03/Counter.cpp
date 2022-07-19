#include "Counter.hpp"

int Counter::_n;

Counter::Counter(void)
{
	this->_n = 0;
}

Counter::Counter(int init_value)
{
	this->_n = init_value;
}

void	Counter::increment(int num)
{
	this->_n += num;
}

void	Counter::decrement(int num)
{
	this->_n -= num;
}

void	Counter::print(void)
{
	std::cout << "n = [" << this->_n << "]\n";
}
