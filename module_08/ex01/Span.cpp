#include "Span.hpp"

Span::Span(void): _maxN(0) {}

Span::Span(unsigned int N): _maxN(N) {}

Span::~Span() {}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span &Span::operator=(const Span &obj)
{
	this->_maxN = obj._maxN;
	return (*this);
}
