#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>

enum value
{
    OPT_NONE,
    OPT_SHRUB,
    OPT_ROBOT,
    OPT_PARDN
};

class Intern
{
private:
public:
    Intern();
    Intern(const Intern &copy);
    ~Intern();

    const Intern &operator=(const Intern &copy);

    AForm *makeForm(const std::string &form, const std::string &target);
};

#endif
