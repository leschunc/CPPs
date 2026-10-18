#include "Span.hpp"
#include <iostream>
/*
#include <sys/time.h>
#define TINY __INT_MAX__ / 32

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
		struct timeval now;
		{
			Span a(TINY);
			for (size_t i = 0; i < TINY; i++)
			{
				a.addNumber(i);
			}
			gettimeofday(&now, 0);
			long start = now.tv_sec * 1000000 + now.tv_usec;

			std::cout << a.longestSpan() << "\n\n";

			gettimeofday(&now, 0);
			long timediff = now.tv_sec * 1000000 + now.tv_usec - start;
			std::cout << timediff / 1000 << std::endl;

			gettimeofday(&now, 0);
			start = now.tv_sec * 1000000 + now.tv_usec;

			std::cout << a.fasterLongestSpan() << "\n\n";

			gettimeofday(&now, 0);
			timediff = now.tv_sec * 1000000 + now.tv_usec - start;
			std::cout << timediff / 1000 << std::endl;

			std::cout << a.shortestSpan() << "\n\n";
		}
	}
}
 */

# define TINY 1000000000
#include <sys/time.h>

void currentTest()
{
	{
		srand(time(0));
		struct timeval now;

		Span a(TINY);
		for (size_t i = 0; i < TINY; i++)
		{
			a.addNumber(TINY - i /* rand() */);
		}
		std::cout << "start" << std::endl;
		gettimeofday(&now, 0);
		long start = now.tv_sec * 1000000 + now.tv_usec;

		std::cout << a.myLongest() << "\n\n";
		// std::cout << a.myShortestSpan() << "\n\n";

		gettimeofday(&now, 0);
		long timediff = now.tv_sec * 1000000 + now.tv_usec - start;
		std::cout << timediff / 1000 << std::endl;

		gettimeofday(&now, 0);
		start = now.tv_sec * 1000000 + now.tv_usec;
		std::cout << a.longestSpan() << "\n\n";
		// std::cout << a.shortestSpan() << "\n\n";

		gettimeofday(&now, 0);
		timediff = now.tv_sec * 1000000 + now.tv_usec - start;
		std::cout << timediff / 1000 << std::endl;
	}
}

int main()
{

	// completeTests();

	currentTest();

	return 0;
}
