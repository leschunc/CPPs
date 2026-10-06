#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &ref);
	~RobotomyRequestForm();

	const RobotomyRequestForm &operator=(const RobotomyRequestForm &ref);

	const std::string &getTarget() const;
	void setTarget(const std::string &target);

	void execute(Bureaucrat const &executor) const;

	class FailedRobotomy : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Robotomy failed";
		}
	};
};

#endif