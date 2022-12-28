#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

		MutantStack() {};
		MutantStack(const MutantStack& obj) { *this = obj; };
		MutantStack& operator=(const MutantStack& obj) { (void)obj; return (*this); };
		~MutantStack() {};

		iterator begin() { return (this->c.begin()); }
		iterator end() { return (this->c.end()); }
		reverse_iterator rbegin() { return (this->c.rbegin()); }
		reverse_iterator rend() { return (this->c.rend()); }
};

#endif
