#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
	private:
		unsigned int _maxN;

	public:
		Span(void);
		Span(unsigned int N);
		~Span(void);
		Span(const Span &obj);
		Span &operator=(const Span &obj);

		void	addNumber(int num);

		int		shortestSpan();
		int		longestSpan();
};

#endif
