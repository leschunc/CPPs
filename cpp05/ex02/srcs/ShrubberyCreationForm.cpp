#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) : AForm(ref), target(ref.target)
{
    if (this == &ref)
        return;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
const ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
    AForm::operator=(ref);
    this->target = ref.target;
    return *this;
}

const std::string &ShrubberyCreationForm::getTarget() const { return target; }

void ShrubberyCreationForm::setTarget(const std::string &target) { this->target = target; }