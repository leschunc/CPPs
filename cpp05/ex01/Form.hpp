#ifndef FORM_HPP
#define FORM_HPP

// #include "Bureaucrat.hpp"
#include <iostream>
#include <cmath>

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool signedDoc;
    const int signGrade;
    const int execGrade;

public:
    Form();
    Form(const std::string& name, int signGrade, int execGrade);
    Form(const Form &ref);
    ~Form();

    const Form &operator=(const Form &ref);

    const std::string &getName()  const;
    int getSignedDoc() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void    beSigned(const Bureaucrat& worker);

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Form's grade too high";
        }
    };
    
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Form's grade too low";
        }
    };
};

std::ostream & operator<<(std::ostream &os, const Form &ref);

#endif