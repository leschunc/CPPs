#include "Span.hpp"
#include <iostream>

void canonTest()
{
	{
		Span a(3);
		Span b(a);
		a = b;
		Span c(b);
	}
	{
		const Span a(3);
		Span b(a);
		b = a;
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
}

void currentTest()
{
}

int main()
{
	// canonTest();

	currentTest();

	return 0;
}
