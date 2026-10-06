#include "Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &copy)
{
    if (this == &copy)
        return;
}

const Intern &Intern::operator=(const Intern &copy)
{
    // lol
    if (this == &copy)
        return *this;
    return *this;
}

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{
    std::string arr[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int index = -1;

    for (size_t i = 0; i < 3; i++)
    {
        if (form.compare(arr[i]) == 0)
            index = i;
    }
    switch (index)
    {
    case 0:
        return (new ShrubberyCreationForm(target));
    case 1:
        return (new RobotomyRequestForm(target));
    case 2:
        return (new PresidentialPardonForm(target));
    default:
    {
        std::cerr << "This form doesn't exist\n";
        return (NULL);
    }
    }
}
