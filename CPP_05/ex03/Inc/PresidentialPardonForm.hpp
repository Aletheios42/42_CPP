#pragma once

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
        virtual ~PresidentialPardonForm();
     
        virtual void execute(Bureaucrat const & executor) const;
};
