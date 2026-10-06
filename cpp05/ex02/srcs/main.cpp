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

	PresidentialPardonForm pardon("Lara");

	// pardon.beSigned(boss);
	RobotomyRequestForm surgery("Lula");
	ShrubberyCreationForm seeds("Home");

	peasant.signForm(seeds);
	boss.signForm(seeds);

	peasant.executeForm(seeds);
	boss.executeForm(seeds);

	std::cout << "------------------------------\n";

	peasant.signForm(surgery);
	boss.signForm(surgery);

	peasant.executeForm(surgery);
	boss.executeForm(surgery);

	std::cout << "------------------------------\n";

	peasant.signForm(pardon);
	boss.signForm(pardon);

	peasant.executeForm(pardon);
	boss.executeForm(pardon);

	return 0;
}
