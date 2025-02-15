/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismirand <ismirand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:53:24 by ismirand          #+#    #+#             */
/*   Updated: 2025/02/15 15:55:58 by ismirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool has_digit(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
		if (str[i] >= '0' && str[i] <= '9')
			return (true);
	return (false);
}

bool has_letter(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
		if (str[i] < '0' || str[i] > '9')
			return (true);
	return (false);
}

/* std::string truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
} */