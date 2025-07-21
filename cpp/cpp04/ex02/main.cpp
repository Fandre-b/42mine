/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:47:42 by tblaase           #+#    #+#             */
/*   Updated: 2025/04/21 17:29:08 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


//cant do both since its abstract;

int main()
{
	// Allocate a Dog object on the heap and use a base class pointer
	const AAnimal *my_animal = new Dog();
	std::cout << "Animal type (via pointer): " << my_animal->getType() << std::endl;
	delete my_animal; // Clean up heap allocation

	// Allocate a Dog object on the stack
	const Dog my_animal2;

	// Use a reference to AAnimal
	const AAnimal &my_animal_ref = my_animal2;
	std::cout << "Animal type (via reference): " << my_animal_ref.getType() << std::endl;

	return 0;
}

// int main()
// {
	// But not directly by use of 
	// const AAnimal *my_animal = new AAnimal();
	// const AAnimal my_animal2;
	// return 0;
// }

