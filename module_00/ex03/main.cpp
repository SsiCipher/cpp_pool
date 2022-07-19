#include "Counter.hpp"

int main(void)
{
	Counter c(20);

	c.print();
	c.increment(5);
	c.decrement(1);
	c.print();
	
	return (0);
}
