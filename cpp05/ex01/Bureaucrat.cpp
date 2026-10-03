#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void Bureaucrat::signForm(Form &paper) const
{
	try
	{
		paper.beSigned(*this);
		std::cout << "Form signed successfully!\n";
	}
	catch(Form::GradeTooHighException &e)
	{
		std::cerr << "Form not signed, reason: " << e.what() << "\n";
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
