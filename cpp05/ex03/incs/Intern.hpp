#include "AForm.hpp"
#include <string>

class Intern
{
private:
    
public:
    Intern(/* args */);
    ~Intern();

    AForm *makeForm(const std::string &form, const std::string &target);
};
