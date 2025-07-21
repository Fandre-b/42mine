/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:04:10 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/09 17:20:25 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <string>
# include <iostream>
# include <iomanip>
// # include <limits>
// #include <sstream>
#include <cstdlib>


class PhoneBook
{
	private:
		// Contact*	_contacts[8];
		Contact _contacts[8];
		void	_removeContact(int i);
		void	_shiftContacts(int i);
		void	_printMenu();
	public:
		PhoneBook();
		~PhoneBook();
		
		void	addContact();
		void	searchContact();
		void	printAllContacts();
		void	ClearStdin();
		bool	IsNumber(std::string input);
};

#endif
