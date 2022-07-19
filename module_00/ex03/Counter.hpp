#ifndef COUNTER_H
# define COUNTER_H

#include <iostream>

class Counter
{
private:
	static int _n;

public:
	Counter(void);
	Counter(int init_value);

	void	increment(int num);
	void	decrement(int num);
	void	print(void);
};

#endif
