#pragma once

#include <iostream>

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

		void setGrade(int grade);
		void setName(const std::string &name);

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
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &rhs);
