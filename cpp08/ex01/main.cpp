#include "Span.hpp"
#include <iostream>

#define TINY 10000
#include <sys/time.h>

void constructorTest()
{
	Span a(3);
	Span b(a);
	Span c(b);
}

void constTest()
{
	const Span a(3);
	Span b(a);
	Span c(b);
}

void fillDisplayRange()
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

void spanTest()
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

void benchTest()
{
	struct timeval now;
	gettimeofday(&now, 0);
	srand(now.tv_usec);

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

void batchTest()
{
	constructorTest();
	constTest();
	fillDisplayRange();
	spanTest();
	benchTest();
}

void workBench()
{
}

int main()
{

	batchTest();

	workBench();

	return 0;
}
