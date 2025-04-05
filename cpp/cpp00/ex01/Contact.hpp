/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:04:05 by fandre-b          #+#    #+#             */
/*   Updated: 2025/03/18 20:27:01 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iomanip>
#include <string>
#include <iostream>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkSecret;
	public:
		//Orthodox Canonical Form
		//contructors / destructors / copy contructor/ copy / operators (=) /
		Contact();
		~Contact();
		// Contact(const Contact& other); // Copy Constructor
        // Contact(Contact&& other) noexcept; // Move Constructor
        // Contact& operator=(const Contact& other); // Copy Assignment Operator
        // Contact& operator=(Contact&& other) noexcept; // Move Assignment Operator

		//setters
		void setFirstName(std::string _firstName);
		void setLastName(std::string _lastName);
		void setNickName(std::string _nickName);
		void setPhoneNumber(std::string _phoneNumber);
		void setDarkSecret(std::string _darkSecret);
		
		//getters
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkSecret();
		
		//methods functions
		void SetContact();
		bool IsEmpty();
};

#endif
