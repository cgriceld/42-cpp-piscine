#include "span.hpp"

Span::Span() {};

Span::Span(unsigned int n) : _n(n), _sorted(false)
{
	_v.reserve(n);
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator = (const Span &copy)
{
	_n = copy._n;
	_v = copy._v;
	_sorted = copy._sorted;
	return (*this);
}

Span::~Span() {};

void Span::addNumber(int n)
{
	if (_n == _v.size())
		throw AddError();
	_v.push_back(n);
	_sorted = false;
}

unsigned int Span::longestSpan(void) const
{
	if (_v.empty() || _v.size() == 1)
		throw NoSpan();
	return (*std::max_element(_v.cbegin(), _v.cend()) - *std::min_element(_v.cbegin(), _v.cend()));
}

unsigned int Span::shortestSpan(void)
{
	if (_v.empty() || _v.size() == 1)
		throw NoSpan();
	if (!_sorted)
		std::sort(_v.begin(), _v.end());
	_sorted = true;
	unsigned int diff = _v.at(1) - _v.at(0);
	for (int i = 2; i < _n; i++)
		diff = std::min(diff, static_cast<unsigned int>(_v[i] - _v[i - 1]));
	return (diff);
}

const char *Span::AddError::what() const throw()
{
	return ("array is already full / not enough space / wrong iterator range\n");
}

const char *Span::NoSpan::what() const throw()
{
	return ("array is empty or have only one element\n");
}