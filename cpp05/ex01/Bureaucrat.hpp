#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <cmath>

class Form;

class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &ref);
    ~Bureaucrat();

    Bureaucrat &operator=(const Bureaucrat &ref);

    void setGrade(int newGrade);
    int getGrade() const;
    const std::string &getName() const;

    void incrementGrade();
    void decrementGrade();

    void signForm(Form &paper) const ;

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Bureaucrat's grade too high";
        }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Bureaucrat's grade too low";
        }
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &ref);

#endif
