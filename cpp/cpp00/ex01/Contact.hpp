/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:04:05 by fandre-b          #+#    #+#             */
/*   Updated: 2025/04/09 17:21:36 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>
# include <iomanip>
// # include <limits>
// #include <sstream>

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
		
		//methods functions
		void SetContact();
		bool IsEmpty();

		void getContact();
		void printContact();

		std::string getFieldLine(std::string info);
		std::string formatField(const std::string& field);
};

std::string formatField(const std::string& field);

#endif
