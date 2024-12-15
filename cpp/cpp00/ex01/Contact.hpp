/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fandre-b <fandre-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:04:05 by fandre-b          #+#    #+#             */
/*   Updated: 2024/12/15 02:03:34 by fandre-b         ###   ########.fr       */
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
	public:
		Contact();
		~Contact();
		void setFirstName(std::string _firstName);
		void setLastName(std::string _lastName);
		void setNickName(std::string _nickName);
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
};

#endif