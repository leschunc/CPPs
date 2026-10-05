#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
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

	ShrubberyCreationForm form("Garden");

	// AForm simpleForm("Papelito", 50, 150);

	peasant.signForm(form);
	// boss.signForm(form);

	peasant.executeForm(form);
	boss.executeForm(form);

	return 0;
}
