#include "../Inc/Animal.hpp"
#include "../Inc/Dog.hpp"
#include "../Inc/Cat.hpp"

int main()
{
    std::cout << "=== TEST 1: Array de Animales (Subject Reqs) ===" << std::endl;
    const int count = 4;
    Animal* animals[count];

    for (int i = 0; i < count / 2; i++)
        animals[i] = new Dog();
    for (int i = count / 2; i < count; i++)
        animals[i] = new Cat();

    std::cout << "\n--- Sounds ---" << std::endl;
    for (int i = 0; i < count; i++)
        animals[i]->makeSound();

    std::cout << "\n--- Deleting ---" << std::endl;
    for (int i = 0; i < count; i++)
        delete animals[i];

    std::cout << "\n=== TEST 2: Prueba de Deep Copy (Copia Profunda) ===" << std::endl;
    
    Dog* dogA = new Dog();
    
    dogA->getBrain().setIdeas(0, "Tengo hambre");
    
    Dog* dogB = new Dog(*dogA);

    std::cout << "Original: " << dogA->getBrain().getIdeas(0) << std::endl;
    std::cout << "Copia   : " << dogB->getBrain().getIdeas(0) << std::endl;

    std::cout << "\n-- Cambiando idea en la copia --" << std::endl;
    dogB->getBrain().setIdeas(0, "Quiero dormir");

    std::cout << "Original: " << dogA->getBrain().getIdeas(0) << " (Debe seguir siendo 'Tengo hambre')" << std::endl;
    std::cout << "Copia   : " << dogB->getBrain().getIdeas(0) << std::endl;

    delete dogA;
    delete dogB;

    return 0;
}