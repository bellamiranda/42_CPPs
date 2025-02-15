#ifndef PHONEBOOK_HPP

#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int saved_contacts;
		int	oldest_contact;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void add();
		void search();
		void print_all_contacts();
		void print_index();
};

bool		has_digit(std::string str);
bool 		has_letter(std::string str);
std::string truncate(std::string str);

#endif