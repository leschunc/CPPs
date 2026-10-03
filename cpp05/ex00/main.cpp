#include "Bureaucrat.hpp"
#include <cmath>
#include <sys/time.h>

void firstTry()
{
	try
	{
		Bureaucrat amanda("amanda", 150);
		Bureaucrat claudia("claudia", 1);
		std::cout << amanda;
		std::cout << claudia;
	}
	catch (const std::exception &e)
	{
		std::cerr << "!!! Caught exception !!!\n";
		std::cerr << e.what() << "\n";
	}
	std::cout << "\n________________________________________\n\n\n";
}

void secondTry()
{
	try
	{
		Bureaucrat roberto("roberto", 151);
		std::cout << roberto;
	}
	catch (const std::exception &e)
	{
		std::cerr << "!!! Caught exception !!!\n";
		std::cerr << e.what() << "\n";
	}
	std::cout << "\n________________________________________\n\n\n";
}

void thirdTry()
{
	try
	{
		Bureaucrat tania("tania", 1);
		std::cout << tania;
		tania.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "!!! Caught exception !!!\n";
		std::cerr << e.what() << "\n";
	}
	std::cout << "\n________________________________________\n\n\n";
}

int main()
{
	// seed
	{
		struct timeval now;
		gettimeofday(&now, NULL);
		srand(now.tv_usec);
	}

	firstTry();
	secondTry();
	thirdTry();

	return 0;
}
