/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:04:05 by fandre-b          #+#    #+#             */
/*   Updated: 2025/01/09 16:30:17 by fandre-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>
# include <ctime>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber; //TODO this is printed when i select the contact index
		std::string _darkSecret;
	public:
		Contact();
		~Contact();
		void setFirstName(std::string _firstName);
		void setLastName(std::string _lastName);
		void setNickName(std::string _nickName);
		void setPhoneNumber(std::string _phoneNumber);
		void setDarkSecret(std::string _darkSecret);
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkSecret();
};

#endif