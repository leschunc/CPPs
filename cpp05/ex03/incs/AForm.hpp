#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <cmath>

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool signedDoc;
    const int signGrade;
    const int execGrade;

    void setSignedDoc(bool signedness);

public:
    AForm();
    AForm(const std::string &name, int signGrade, int execGrade);
    AForm(const AForm &ref);
    virtual ~AForm() = 0;

    const AForm &operator=(const AForm &ref);

    const std::string &getName() const;
    bool getSignedDoc() const;
    int getSignGrade() const;
    int getExecGrade() const;


    void beSigned(const Bureaucrat &worker);
    virtual void execute(Bureaucrat const &executor) const;

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

    class UnsignedForm : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Form is unsigned";
        }
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &ref);

#endif