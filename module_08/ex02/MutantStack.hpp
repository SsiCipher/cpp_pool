#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H

# include <iostream>
# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack() {};
		MutantStack(const MutantStack& obj) { *this = obj; };
		MutantStack& operator=(const MutantStack& obj) { (void)obj; return (*this); };
		~MutantStack() {};

		typename std::stack<T>::container_type::iterator begin() { return (this->c.begin()); }
		typename std::stack<T>::container_type::const_iterator begin() { return (this->c.begin()); }
		typename std::stack<T>::container_type::iterator end() { return (this->c.end()); }
		typename std::stack<T>::container_type::const_iterator end() { return (this->c.end()); }
};

#endif
