#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : name("unnamed"), signedDoc(false), signGrade(rand() % 150 + 1), execGrade(rand() % 150 + 1)
{
}

AForm::AForm(const AForm &ref) : name(ref.name), signedDoc(ref.signedDoc), signGrade(ref.signGrade), execGrade(ref.execGrade)
{
    if (this == &ref)
        return;
    if (execGrade > 150 || signGrade > 150)
        throw GradeTooLowException();
    if (execGrade < 1 || signGrade < 1)
        throw GradeTooHighException();
}

AForm::AForm(const std::string &name, int signGrade, int execGrade) : name(name), signedDoc(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
}

AForm::~AForm()
{
}

const AForm &AForm::operator=(const AForm &ref)
{
    if (this == &ref)
        return *this;
    this->signedDoc = ref.signedDoc;
    return *this;
}

const std::string &AForm::getName() const
{
    return name;
}

bool AForm::getSignedDoc() const
{
    return signedDoc;
}

int AForm::getSignGrade() const
{
    return signGrade;
}

int AForm::getExecGrade() const
{
    return execGrade;
}

void AForm::setSignedDoc(bool signedness)
{
    signedDoc = signedness;
}

void AForm::beSigned(const Bureaucrat &worker)
{
    if (this->signGrade < worker.getGrade())
        throw AForm::GradeTooLowException();
    this->signedDoc = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (this->getSignedDoc() == false)
    {
        throw AForm::UnsignedForm();
    }
    if (this->execGrade < executor.getGrade())
        throw AForm::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &ref)
{
    os << "AForm:\t\t" << ref.getName() << "\nSign grade:\t" << ref.getSignGrade() << "\nExec grade:\t" << ref.getExecGrade();
    if (ref.getSignedDoc())
        os << "\nIs\t\tSigned\n";
    else
        os << "\nIs\t\tUnsigned\n";
    return os;
}
