#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("unnamed"), grade(rand() % 150 + 1) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
	if (grade > 150)
		throw(GradeTooLowException());
	if (grade < 1)
		throw(GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : name(ref.name), grade(ref.grade)
{
	if (this == &ref)
		return;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref)
{
	if (this == &ref)
		return *this;
	this->grade = ref.grade;
	return *this;
}

void Bureaucrat::setGrade(int newGrade)
{
	grade = newGrade;
	if (grade > 150)
		throw(GradeTooLowException());
	if (grade < 1)
		throw(GradeTooHighException());
}

int Bureaucrat::getGrade() const { return this->grade; }
const std::string &Bureaucrat::getName() const { return this->name; }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &ref)
{
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << "\n";
	return os;
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << "\n";
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << "\n";
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << "\n";
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << "\n";
	}
	catch (std::exception& e)
	{
		std::cerr << "Failed execution: " << e.what() << "\n";
	}
}

void Bureaucrat::incrementGrade()
{
	setGrade(getGrade() - 1);
}

void Bureaucrat::decrementGrade()
{
	setGrade(getGrade() + 1);
}
