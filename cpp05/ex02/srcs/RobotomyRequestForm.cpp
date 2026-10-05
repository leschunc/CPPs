#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Unspecified target") {}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) : AForm(ref), target(ref.target)
{
    if (this == &ref)
        return;
}
RobotomyRequestForm::~RobotomyRequestForm() {}
const RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
    AForm::operator=(ref);
    this->target = ref.getTarget();
    return *this;
}

const std::string &RobotomyRequestForm::getTarget() const { return target; }

void RobotomyRequestForm::setTarget(const std::string &target) { this->target = target; }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);

    if (rand() % 2)
        throw FailedRobotomy();
    
    std::cout << "Drilling noises: " << getTarget() << " has been robotomized\n";
}
