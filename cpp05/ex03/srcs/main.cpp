#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cmath>
#include <sys/time.h>

void seed()
{
	struct timeval now;
	gettimeofday(&now, NULL);
	srand(now.tv_usec);
}

int main()
{
	seed();

	Bureaucrat boss("boss", 1);
	Bureaucrat peasant("peasy", 150);
	Intern pedro;
	AForm *genericForm;

	std::string arr[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	std::string targets[] = {"goncalo", "denisa", "ricardo"};

	for (size_t i = 0; i < 4; i++)
	{
		genericForm = pedro.makeForm(arr[rand() % 3], targets[rand() % 3]);
		if (!genericForm)
		{
			std::cerr << "Failed to create a form\n";
			return 1;
		}
		boss.signForm(*genericForm);
		peasant.executeForm(*genericForm);
		boss.executeForm(*genericForm);
		std::cout << "___________________________\n";
		delete genericForm;
	}
	return 0;
}
