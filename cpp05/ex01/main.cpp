#include "Bureaucrat.hpp"
#include "Form.hpp"
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

	Form simpleForm("Papelito", 50, 150);

	peasant.signForm(simpleForm);
	boss.signForm(simpleForm);

	return 0;
}
