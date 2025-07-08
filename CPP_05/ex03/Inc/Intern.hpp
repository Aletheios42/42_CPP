#pragma once

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {

    public:
        Intern();
        Intern(const Intern &other);
        Intern& operator=(const Intern& rhs);
        ~Intern();

        AForm *makeForm(std::string formName, std::string formTarget);
};
