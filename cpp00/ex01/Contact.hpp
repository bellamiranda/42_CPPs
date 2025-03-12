/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:15:07 by ismirand          #+#    #+#             */
/*   Updated: 2025/03/11 16:01:59 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>//setw

#include <string.h>
#include <cstdlib>
#include <unistd.h>

class Contact {

public:
	Contact();
	~Contact();
	void	setFirstName();
	void	setLastName();
	void	setNickname();
	void	setPhoneNumber();
	void	setDarkestSecret();
	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickname();
	std::string	getPhoneNumber();
	std::string	getDarkestSecret();

private:
	std::string	_FirstName;
	std::string	_LastName;
	std::string	_Nickname;
	std::string	_PhoneNumber;
	std::string	_DarkestSecret;

};

#define RESET	"\033[0m"
#define RED		"\033[31;1m"
#define CYAN	"\033[36;1m"
#define GREEN	"\033[32;1m"
#define MGT		"\033[35;1m"
#define CTRLD 	RED << "CTRL+D Exit PhoneBook !" << RESET

#endif