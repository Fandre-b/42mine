/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:58:57 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/21 10:40:59 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
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