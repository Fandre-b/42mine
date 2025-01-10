/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:04:10 by fandre-b          #+#    #+#             */
/*   Updated: 2025/01/09 16:08:44 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <string>
# include <iostream>
# include <iomanip>
# include <ctime>
# include "Contact.hpp"

class PhoneBook
{
	private:
		int		_index;
		Contact*	_contacts[8];
		void	_removeContact(int i);
		void	_printContact(Contact* _contact, int i);	
		void	_shiftContacts(int i);
		void	_printMenu();
	public:
		PhoneBook();
		~PhoneBook();
		// void	run();
		void	addContact();
		void	searchContact();
		void	printAllContacts();
		// void	printHeader();
		// void	printFooter();
		// void	printContactList();
};

#endif