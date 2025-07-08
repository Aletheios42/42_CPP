#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {

    private:
        std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, const int grade);
        Bureaucrat(const Bureaucrat& ohter);
        Bureaucrat& operator=(const Bureaucrat& burocrat);
        ~Bureaucrat();

		void incrementGrade();
		void decrementGrade();

        std::string getName() const;
        int getGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

        void signForm(Form &toSign);
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &rhs);
