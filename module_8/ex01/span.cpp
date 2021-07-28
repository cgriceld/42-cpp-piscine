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
		throw std::invalid_argument("array is already full\n");
	_v.push_back(n);
	_sorted = false;
}

unsigned int Span::longestSpan(void) const
{
	std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> span;
	if (_v.empty() || _v.size() == 1)
		throw std::invalid_argument("array is empty or has only one element\n");
	span = std::minmax_element(_v.cbegin(), _v.cend());
	return (*span.second - *span.first);
}

unsigned int Span::shortestSpan(void)
{
	if (_v.empty() || _v.size() == 1)
		throw std::invalid_argument("array is empty or has only one element\n");
	if (!_sorted)
		std::sort(_v.begin(), _v.end());
	_sorted = true;
	unsigned int diff = _v.at(1) - _v.at(0);
	for (unsigned int i = 2; i < _n; i++)
		diff = std::min(diff, static_cast<unsigned int>(_v.at(i) - _v.at(i - 1)));
	return (diff);
}