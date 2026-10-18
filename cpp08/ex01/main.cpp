#include "Span.hpp"
#include <iostream>

#define TINY 3
#include <sys/time.h>

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
		srand(time(0));
		struct timeval now;

		Span a(TINY);
		for (size_t i = 0; i < TINY; i++)
		{
			a.addNumber(rand());
		}
		std::cout << "start" << std::endl;
		gettimeofday(&now, 0);
		long start = now.tv_sec * 1000000 + now.tv_usec;

		std::cout << a.longestSpan() << "\n\n";

		gettimeofday(&now, 0);
		long timediff = now.tv_sec * 1000000 + now.tv_usec - start;
		std::cout << timediff / 1000 << std::endl;

		gettimeofday(&now, 0);
		start = now.tv_sec * 1000000 + now.tv_usec;

		std::cout << a.myLongest() << "\n\n";

		gettimeofday(&now, 0);
		timediff = now.tv_sec * 1000000 + now.tv_usec - start;
		std::cout << timediff / 1000 << std::endl;
		gettimeofday(&now, 0);
		start = now.tv_sec * 1000000 + now.tv_usec;

		std::cout << a.shortestSpan() << "\n\n";

		gettimeofday(&now, 0);
		timediff = now.tv_sec * 1000000 + now.tv_usec - start;
		std::cout << timediff / 1000 << std::endl;
		gettimeofday(&now, 0);
		start = now.tv_sec * 1000000 + now.tv_usec;

		std::cout << a.myShortest() << "\n\n";

		gettimeofday(&now, 0);
		timediff = now.tv_sec * 1000000 + now.tv_usec - start;
		std::cout << timediff / 1000 << std::endl;
	}
}

#include <unistd.h>

void currentTest()
{
	srand(time(0));
	int max = -1U/2;
	int curr;
	for (size_t i = 0; i < 3; i++)
	{
		curr = rand();
		if (curr > max - (max / 10))
		{
			std::cout << curr << "\n";
			max = curr;
			// sleep(1);
		}
		// if (rand() < max)
	}
}

int main()
{

	// completeTests();

	currentTest();

	return 0;
}
