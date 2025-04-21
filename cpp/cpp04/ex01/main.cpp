/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:57 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/21 17:08:04 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <iostream>
#include <sstream> // Include this for std::stringstream

int main()
{
    std::cout << std::endl << "Constructing Animals" << std::endl;

    const int animalCount = 6; // Example: 3 Dogs and 3 Cats
    Animal* animals[animalCount];

    // Fill the array with Dogs and Cats
    for (int i = 0; i < animalCount; i++)
    {
        if (i < animalCount / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    
    // print all animals to prove
    std::cout << std::endl << "Testing Intercalation of Dogs and Cats" << std::endl;

    for (int i = 0; i < animalCount; i++)
    {
        std::cout << "Animal " << i << " is a " << animals[i]->getType() << " and it says: ";
        animals[i]->makeSound();
    }
    
    
    std::cout << std::endl << std::endl << "Testing Deep Copy" << std::endl;

    Animal* originalDog = new Dog();
    for (int i = 0; i < 100; i++) {
        std::stringstream ss;
        ss << "Idea " << i; // Concatenate "Idea " and the integer i
        originalDog->setIdea(i, ss.str()); // Pass the resulting string to setIdea
        // dynamic_cast<Dog*>(originalDog)->setIdea(0, "idea" + i);
    }

    std::cout << "Original Dog's Ideas:" << std::endl;
    originalDog->getIdeas();

    Animal* copiedDog = new Dog(*dynamic_cast<Dog*>(originalDog));

    std::cout << std::endl << "Copied Dog's Ideas (after deep copy):" << std::endl;
    copiedDog->getIdeas();

    std::cout << std::endl << "Modifying Copied Dog's Ideas..." << std::endl;
    copiedDog->setIdea(0, "I want to sleep.");
    copiedDog->setIdea(1, "I need to dig a hole.");

    std::cout << std::endl << "Original Dog's Ideas (should remain unchanged):" << std::endl;
    originalDog->getIdeas();

    std::cout << std::endl << "Copied Dog's Ideas (after modification):" << std::endl;
    copiedDog->getIdeas();

    std::cout << std::endl << std::endl << "Cleaning Up Individual Dogs" << std::endl;
    delete originalDog;
    delete copiedDog;

    std::cout << std::endl << std::endl << "Cleaning Up Animal Array" << std::endl;

    // Delete all animals in the array
    for (int i = 0; i < animalCount; i++)
        delete animals[i];

    std::cout << std::endl << std::endl << "Program Finished" << std::endl;

    return 0;
}