#ifndef SHRUBBERRYCREATIONFORM_HPP
#define SHRUBBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &name);
	ShrubberyCreationForm(const ShrubberyCreationForm &ref);
	~ShrubberyCreationForm();

	const ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ref);

	const std::string &getTarget() const;
	void setTarget(const std::string &target);

	void execute(Bureaucrat const &executor) const;
};

#endif