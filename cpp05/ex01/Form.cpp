#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name("unnamed"), signedDoc(false), signGrade(rand() % 150 + 1), execGrade(rand() % 150 + 1)
{
}

Form::Form(const Form &ref) : name(ref.name), signedDoc(ref.signedDoc), signGrade(ref.signGrade), execGrade(ref.execGrade)
{
    if (this == &ref)
        return;
    if (execGrade > 150 || signGrade > 150)
        throw GradeTooLowException();
    if (execGrade < 1 || signGrade < 1)
        throw GradeTooHighException();
}

Form::Form(const std::string &name, int signGrade, int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
}

Form::~Form()
{
}

const Form &Form::operator=(const Form &ref)
{
    if (this == &ref)
        return *this;
    this->signedDoc = ref.signedDoc;
    return *this;
}

const std::string &Form::getName() const
{
    return name;
}

int Form::getSignedDoc() const
{
    return signedDoc;
}

int Form::getSignGrade() const
{
    return signGrade;
}

int Form::getExecGrade() const
{
    return execGrade;
}

void Form::beSigned(const Bureaucrat &worker)
{
    this->signedDoc = true;
    if (this->signGrade < worker.getGrade())
        throw GradeTooHighException();
}

std::ostream &operator<<(std::ostream &os, const Form &ref)
{
    os << "Form:\t\t" << ref.getName() << "\nSign grade:\t" << ref.getSignGrade() << "\nExec grade:\t" << ref.getExecGrade();
    if (ref.getSignedDoc())
        os << "\nIs\t\tSigned\n";
    else
        os << "\nIs\t\tUnsigned\n";
    return os;
}
