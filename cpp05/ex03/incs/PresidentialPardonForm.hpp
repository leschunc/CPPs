#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
private:
	std::string target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &ref);
	~PresidentialPardonForm();

	const PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);

	const std::string &getTarget() const;
	void setTarget(const std::string &target);

	void execute(Bureaucrat const &executor) const;
};

#endif