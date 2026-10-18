#include "Span.hpp"
#include <iostream>
#include <list>

#define TINY 1000000
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

	Span a(TINY);
	for (size_t i = 0; i < TINY; i++)
	{
		a.addNumber(rand());
	}
	long start;
	long timediff;
	{
		std::cout << "start" << std::endl;
		gettimeofday(&now, 0);
		start = now.tv_sec * 1000000 + now.tv_usec;
		std::cout << a.longestSpan() << "\n\n";
		gettimeofday(&now, 0);
		timediff = now.tv_sec * 1000000 + now.tv_usec - start;
		std::cout << timediff / 1000 << std::endl;
	}
	{
		gettimeofday(&now, 0);
		start = now.tv_sec * 1000000 + now.tv_usec;
		std::cout << a.shortestSpan() << "\n\n";
		gettimeofday(&now, 0);
		timediff = now.tv_sec * 1000000 + now.tv_usec - start;
		std::cout << timediff / 1000 << std::endl;
	}
}

void subjectTest()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void fillerTest()
{
	size_t cap = 42;

	Span source(cap);
	std::list<int> filler;
	for (size_t i = 0; i < cap; i++)
		filler.push_back(rand());

	while (1)
	{
		try
		{
			source.fill(filler.begin(), filler.end());
			source.disp();
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			break;
		}
	}
}

void batchTest()
{
	srand(time(0));

	constructorTest();
	std::cout << "_________________\n\nEND		|\n_________________\n\n";
	constTest();
	std::cout << "_________________\n\nEND		|\n_________________\n\n";
	fillDisplayRange();
	std::cout << "_________________\n\nEND		|\n_________________\n\n";
	spanTest();
	std::cout << "_________________\n\nEND		|\n_________________\n\n";
	benchTest();
	std::cout << "_________________\n\nEND		|\n_________________\n\n";
	subjectTest();
	std::cout << "_________________\n\nEND		|\n_________________\n\n";
	fillerTest();
	std::cout << "_________________\n\nEND		|\n_________________\n\n";
}

int main()
{

	batchTest();

	return 0;
	
}
