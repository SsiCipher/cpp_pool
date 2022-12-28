#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span
{
	private:
		unsigned int		_maxN;
		std::vector<int>	_content;

	public:
		Span(void);
		Span(unsigned int N);
		~Span(void);
		Span(const Span &obj);
		Span &operator=(const Span &obj);

		void	addNumber(int num);

		int		shortestSpan() const;
		int		longestSpan() const;

		void	debugDisplaySpan() {
			for (std::vector<int>::iterator i = this->_content.begin(); i != this->_content.end(); i++)
				std::cout << *i << std::endl;
		}

		class SpanIsFullException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class SpanSmallSizeException: public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
