#include "Span.hpp"

Span::Span(void): _maxN(0) {}

Span::Span(unsigned int N): _maxN(N) {}

Span::~Span() {}

Span::Span(const Span &obj) { *this = obj; }

Span &Span::operator=(const Span &obj)
{
	this->_maxN = obj._maxN;
	this->_content = obj._content;
	return (*this);
}

void	Span::addNumber(int num)
{
	if (this->_content.size() == this->_maxN)
		throw SpanIsFullException();
	this->_content.push_back(num);
}

int		Span::shortestSpan() const
{
	std::vector<int> tmpContent = this->_content;

	if (this->_content.size() <= 1)
		throw SpanSmallSizeException();
	// std::sort(tmpContent.begin(), tmpContent.end());
	return (0);
}

int		Span::longestSpan() const
{
	std::vector<int> tmpContent = this->_content;

	if (this->_content.size() <= 1)
		throw SpanSmallSizeException();
	// std::sort(tmpContent.begin(), tmpContent.end());
	return (0);
}

const char* Span::SpanIsFullException::what() const throw()
{
    return "The span is full";
}

const char* Span::SpanSmallSizeException::what() const throw()
{
    return "The span doesn't have enough elements";
}
