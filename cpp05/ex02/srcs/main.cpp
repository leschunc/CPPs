#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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
	Bureaucrat peasant("peasant", 150);

	PresidentialPardonForm pardon("Jesus");

	peasant.signForm(pardon);
	boss.signForm(pardon);

	peasant.executeForm(pardon);
	boss.executeForm(pardon);

	return 0;
}
