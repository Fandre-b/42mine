/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:57 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/21 11:43:07 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main2()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << "->destruct" << std::endl;
    delete i;
    delete j;
    delete meta;
    
    std::cout << std::endl << "-----my Tests----" << std::endl << std::endl;
    // ...
    //cpp03 way of doing it
    
    const Dog my_doggo2;
    const Dog *ptr_doggo = new Dog();
    my_doggo2.makeSound();
    ptr_doggo->makeSound();
    
    std::cout << "->destruct" << std::endl;
    delete ptr_doggo;
    
    
    std::cout << std::endl << "-----slicing----" << std::endl << std::endl;
    // splicing exemple
    
    Animal my_doggo;
    // const Animal my_doggo = Dog(); // calls coppy
    my_doggo = Dog(); // calls assigment directly
    my_doggo.makeSound();
    std::cout << "->destruct" << std::endl;


    //wrong animal test
    std::cout << std::endl << "-----no virtual (wrong Animal)----" << std::endl << std::endl;
    
    const WrongAnimal* meta2 = new WrongAnimal();
    // const WrongAnimal* j2 = new Dog();
    const WrongAnimal* i2 = new WrongCat();
    // std::cout << j2->getType() << " " << std::endl;
    std::cout << i2->getType() << " " << std::endl;
    i2->makeSound(); //will output the WrongCat sound!
    // j2->makeSound();
    meta2->makeSound();

    std::cout << "->destruct" << std::endl;
    delete i2;
    // delete j2;
    delete meta2;


    std::cout << std::endl << "-----Release memmory----" << std::endl << std::endl;

    
    return 0;
}

int main()
{
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const Animal	*meta[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			meta[i] = new Cat();
			if (meta[i] == NULL)
			{
				std::cerr << "Cat allocation failed";
				std::cerr << "Exiting process now";
			}
		}
		else
		{
			meta[i] = new Dog();
			if (meta[i] == NULL)
			{
				std::cerr << "Dog allocation failed";
				std::cerr << "Exiting process now";
			}
		}
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		std::cout << "Animal _type: " << meta[i]->getType() << std::endl;
		meta[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
		delete(meta[i]);

//THIS PART IS FOR TESTING DEEP COPY ↓

	std::cout << std::endl << std::endl;
	std::cout << "#### showing that the copy constructor creates a deep copy ####" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	Dog *a = new Dog();
	// Cat *a = new Cat();
	if (a == NULL)
	{
        std::cerr << "Allocation failed";
		std::cerr << "Exiting the process now." << std::endl;
	}

	a->setIdea(0, "I have to sniff it");
	a->setIdea(1, "I have to pee on it");
	a->setIdea(2, "I have to sniff it again");
	a->setIdea(101, "some shit");

	Dog *b = new Dog(*a);
	// Cat *b = new Cat(*a);
	if (b == NULL)
	{
        std::cerr << "Allocation failed";
		std::cerr << "Exiting the process now." << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting a\033[0m" << std::endl;
	std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
	a->getIdeas();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
	delete(a);
	std::cout << std::endl;

	std::cout << "\033[34mTesting b\033[0m" << std::endl;
	std::cout << "The " << b->getType() << " b has the following ideas: " << std::endl;
	b->getIdeas();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
	delete(b);

	return (0);
}