#ifndef CONTACT_HPP

#define CONTACT_HPP

#include <iostream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string darkest_secret;
		std::string number;
	public:
		Contact();
		~Contact();
		void set_first_name();
		void set_last_name();
		void set_nickname();
		void set_darkest_secret();
		void set_number();
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nickname();
		std::string get_darkest_secret();
		std::string get_number();
};

#endif