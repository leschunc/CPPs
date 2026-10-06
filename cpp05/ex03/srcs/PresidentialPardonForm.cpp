#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Unspecified target") {}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) : AForm(ref), target(ref.target)
{
    if (this == &ref)
        return;
}
PresidentialPardonForm::~PresidentialPardonForm() {}
const PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
    AForm::operator=(ref);
    this->target = ref.target;
    return *this;
}

const std::string &PresidentialPardonForm::getTarget() const { return target; }

void PresidentialPardonForm::setTarget(const std::string &target) { this->target = target; }

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);

    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}
