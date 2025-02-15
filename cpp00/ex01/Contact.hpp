/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:15:07 by ismirand          #+#    #+#             */
/*   Updated: 2025/02/15 16:02:04 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

#include <string.h>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>

class Contact {

private:
	std::string	FirstName;
	std::string	LastName;
	std::string	Nickname;
	std::string	PhoneNumber;
	std::string	DarkestSecret;

public:
	Contact();
	~Contact();
	void	set_FirstName();
	void	set_LastName();
	void	set_Nickname();
	void	set_PhoneNumber();
	void	set_DarkestSecret();
	std::string	get_FirstName();
	std::string	get_LastName();
	std::string	get_Nickname();
	std::string	get_PhoneNumber();
	std::string	get_DarkestSecret();
};

#define RESET	"\033[0m"
#define RED		"\033[31;1m"
#define GREEN	"\033[32;1m"
#define MGT		"\033[35;1m"
#define CYAN	"\033[36;1m"
#define CTRLD 	RED << "CTRL+D Exit PhoneBook !" << RESET

#endif