#include "MutantStack.hpp"

int main()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "The top is : " << mstack.top() << std::endl;
	
	mstack.pop();

	std::cout << "the stack has : " << mstack.size() << " elements." << std::endl;

	mstack.push(3);
	mstack.push(90);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::reverse_iterator ite = mstack.rend();

	++it;
	--it;

	for (; it != mstack.end(); it++)
		std::cout << *it << std::endl;

	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }

	std::stack<int> s(mstack);

	return (0);
}
