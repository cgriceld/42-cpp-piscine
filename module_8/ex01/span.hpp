#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <cstdlib>

class Span
{
public:

	class AlreadyFull : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class NoSpan : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	Span(unsigned int n);
	Span(const Span &copy);
	virtual ~Span();

	Span &operator = (const Span &copy);

	void addNumber(int n);
	template <typename T>
	void addNumber(T &begin, T&end);

	unsigned int longestSpan(void) const;
	unsigned int shortestSpan(void);

private:
	Span();
	unsigned int _n;
	std::vector<int> _v;
	bool _sorted;
};

template <typename T>
void addNumber(T &beg, T&end)
{
	if (end < begin )
}

#endif