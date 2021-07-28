#include "span.hpp"
#include <iostream>

int main(void)
{
	srand(time(0));
	{
		std::cout << "BASIC CHECK & ADDNUMBER EXCEPTION\n";
		Span span(5);

		span.addNumber(5);
		span.addNumber(4);
		span.addNumber(23);
		span.addNumber(0);
		span.addNumber(9);

		try
		{
			span.addNumber(11);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}

		std::cout << "longest : " << span.longestSpan() << ", shortest : " << span.shortestSpan() << std::endl;
		std::cout << "--------------------\n";
	}
	{
		std::cout << "EMPTY / ONE NUMBER SPAN EXCEPTION\n";
		Span span(1);
		Span span1(0);

		span.addNumber(21);

		try
		{
			std::cout << "longest : " << span.longestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}

		try
		{
			std::cout << "shortest : " << span1.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}
		std::cout << "--------------------\n";
	}
	{
		std::cout << "10000 TEST & ITERATOR INIT\n";
		std::vector<int> test(10000);
		for (int i = 0; i < 10000; i++)
			test.push_back(rand());
		Span span(10000);
		span.addNumber(test.cbegin(), test.cend());
		std::cout << "longest : " << span.longestSpan() << ", shortest : " << span.shortestSpan() << std::endl;
		std::cout << "--------------------\n";
	}
	{
		std::cout << "WRONG ITERATOR INIT\n";
		std::vector<int> test(4);
		for (int i = 0; i < 4; i++)
			test.push_back(rand());
		Span span(4);

		try
		{
			span.addNumber(test.cbegin() + 2, test.cbegin());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}

		span.addNumber(1);

		try
		{
			span.addNumber(test.cbegin(), test.cbegin());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what();
		}
		std::cout << "--------------------\n";
	}

	return (0);
}