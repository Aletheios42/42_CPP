#include "../Inc/Animal.hpp"
#include "../Inc/WrongAnimal.hpp"
#include "../Inc/Dog.hpp"
#include "../Inc/Cat.hpp"
#include "../Inc/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n--- WrongAnimal tests ---" << std::endl;

	const WrongAnimal* wrong = new WrongCat();
	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound(); // will output the WrongAnimal sound

	delete wrong;
	return 0;
}
