#pragma once

#include <iostream>
#include "../Inc/Animal.hpp"
#include "../Inc/Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	_brain;

	public:
		Cat();
		Cat(const Cat& other);
        Cat(const std::string& type);
		Cat& operator=(const Cat& other);
		~Cat();

		void	makeSound() const;
		void	setBrain(const Brain& brain);
		Brain&	getBrain() const;
};