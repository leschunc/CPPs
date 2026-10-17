#include "Span.hpp"
#include <iostream>

#define TINY __INT_MAX__ / 2

void completeTests()
{
	{
		Span a(3);
		Span b(a);
		Span c(b);
	}
	{
		const Span a(3);
		Span b(a);
		Span c(b);
	}
	{
		Span a(10);

		for (size_t i = 0; i < 12; i++)
		{
			try
			{
				a.addNumber(i);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}
			a.disp();
		}
	}
	{
		Span a(10);

		a.addNumber(1);
		a.addNumber(2);
		a.addNumber(8);
		a.addNumber(15);
		a.addNumber(2);

		try
		{
			std::cout << a.shortestSpan() << "\n";
			std::cout << a.longestSpan() << "\n";
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		Span a(TINY);
		for (size_t i = 0; i < TINY; i++)
		{
			a.addNumber(i);
		}
		std::cout << a.longestSpan() << "\n\n";
		std::cout << a.shortestSpan() << "\n\n";
	}
}

void currentTest()
{
	
}

int main()
{

	// completeTests();

	currentTest();

	return 0;
}
