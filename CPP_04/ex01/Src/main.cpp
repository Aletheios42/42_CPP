#include "../Inc/Animal.hpp"
#include "../Inc/Dog.hpp"
#include "../Inc/Cat.hpp"
#include "../Inc/Brain.hpp"

int main(void)
{
    // Creación y eliminación básica con new y delete
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j;  // Shold not create a leak
    delete i;

    std::cout << "--------------------------------" << std::endl;

    // Prueba de array de animales
    Animal *animals[6];

    for (int i = 0; i < 3; i++)
        animals[i] = new Dog();
    for (int i = 3; i < 6; i++)
        animals[i] = new Cat();

    for (int i = 0; i < 6; i++)
        animals[i]->makeSound();

    for (int i = 0; i < 6; i++)
        delete animals[i];

    std::cout << "--------------------------------" << std::endl;

    // Copia profunda
    Dog d1;
    d1.getBrain().setIdeas(0, "I want a bone!");
    Dog d2 = d1;

    std::cout << "Dog 1 idea: " << d1.getBrain().getIdeas(0) << std::endl;
    std::cout << "Dog 2 idea: " << d2.getBrain().getIdeas(0) << std::endl;

    return 0;
}

