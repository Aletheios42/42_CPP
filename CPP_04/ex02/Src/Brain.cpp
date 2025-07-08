#include "../Inc/Brain.hpp"

Brain::Brain() { 
    std::cout << "Constructor de Brain was called" << std::endl;
}

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; ++i)
        _ideas[i] = other._ideas[i];
    std::cout << "Constructor de Brain copia called" << std::endl;
}

Brain& Brain::operator=(const Brain& brain) { 
    if (this != &brain) {
        for(int i = 0; i < 99; i++)
            _ideas[i] = brain._ideas[i];
    }
    std::cout << "Constructor de Brain copy was called" << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain 's called" << std::endl;
}

std::string Brain::getIdeas(int const index)const
{
	if (index < 0 || index > 99)
		return (std::cout << "Error: Ideas's index goes from 0 to 99" << std::endl, "");
	return (this->_ideas[index]);
}

void Brain::setIdeas(int const index, std::string const idea)
{
	if (index < 0 || index > 99)
	{
		std::cout << "Error: Ideas's index goes from 0 to 99" << std::endl;
		return ;
	}
	this->_ideas[index] = idea;
}
