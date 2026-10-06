#ifndef INTERN_HPP
#define INTERN_HPP

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

enum value
{
    OPT_NONE,
    OPT_SHRUB,
    OPT_ROBOT,
    OPT_PARDN
};

int formStrToEnum(const std::string &form)
{
    if (form.compare("shrubbery creation") == 0)
        return OPT_SHRUB;
    else if (form.compare("robotomy request") == 0)
        return OPT_ROBOT;
    else if (form.compare("presidential pardon") == 0)
        return OPT_PARDN;
    else
        return OPT_NONE;
}

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{
    switch (formStrToEnum(form))
    {
    case OPT_SHRUB:
        return (new ShrubberyCreationForm(target));
        break;
    case OPT_ROBOT:
        return (new RobotomyRequestForm(target));
        break;
    case OPT_PARDN:
        return (new PresidentialPardonForm(target));
        break;

    default:
        return (NULL);
    }
}

#endif