/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:54:28 by ismirand          #+#    #+#             */
/*   Updated: 2025/02/15 15:51:32 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PB_HPP
#define PB_HPP

#include "Contact.hpp"

class PhoneBook {

private:
	Contact	Contacts[8];
	int saved_contacts;
	int	oldest_contact;

public:
	PhoneBook();
	~PhoneBook();
	void	add();
	void	search();
	void	printPhoneBook();
	void	printContact();
};

bool		has_digit(std::string str);
bool 		has_letter(std::string str);
std::string truncate(std::string str);

#endif