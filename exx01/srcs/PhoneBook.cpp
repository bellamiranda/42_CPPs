#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->oldest_contact = 0;
	this->saved_contacts = 0;
	std::cout << "\033[34m" << "     WELCOME TO THE AMAZING PHONEBOOK     " << "\033[0m" << std::endl;
	std::cout << "-------------------------------------------\n" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "\033[31m" << "Exiting PhoneBook, see you soon!" << "\033[0m" << std::endl;
}

void PhoneBook::add()
{
	if (saved_contacts < 8)
	{
		std::cout << "\n-------------------------------------------" << "\033[0m" << std::endl;
		std::cout << "\033[34m" << "            ADDING A NEW CONTACT           \n" << "\033[0m" << std::endl;
		contacts[saved_contacts].set_first_name();
		contacts[saved_contacts].set_last_name();
		contacts[saved_contacts].set_nickname();
		contacts[saved_contacts].set_darkest_secret();
		contacts[saved_contacts].set_number();
		std::cout << "\033[34m" << "\nNew contact " << contacts[saved_contacts].get_first_name() 
			<< " has been added!" << "\033[0m" << std::endl << std::endl;
		saved_contacts += 1;
		return;
	}
	std::cout << "\033[34m" << "\nThe oldest contact " << contacts[oldest_contact].get_first_name() 
	<< " has been deleted!" << "\033[0m" << std::endl << std::endl;
	contacts[oldest_contact].set_first_name();
	contacts[oldest_contact].set_last_name();
	contacts[oldest_contact].set_nickname();
	contacts[oldest_contact].set_darkest_secret();
	contacts[oldest_contact].set_number();
	std::cout << "\033[34m" << "\nNew contact " << contacts[oldest_contact].get_first_name() 
	<< " has been added!" << "\033[0m" << std::endl << std::endl;
	if (oldest_contact < 7)
		oldest_contact += 1;
	else
		oldest_contact = 0;
}

void PhoneBook::print_all_contacts()
{
	const int	width = 10;

	std::cout << "---------------- CONTACTS -----------------\n" << std::endl;
	std::cout << std::setw(width) << truncate("INDEX") << "|";
	std::cout << std::setw(width) << truncate("FIRST NAME") << "|";
	std::cout << std::setw(width) << truncate("LAST NAME") << "|";
	std::cout << std::setw(width) << truncate("NICKNAME") << std::endl;
	for (int i = 0; i < saved_contacts; i++)
	{
		std::cout << std::setw(width) << i + 1 << "|";
		std::cout << std::setw(width) << truncate(contacts[i].get_first_name()) << "|";
		std::cout << std::setw(width) << truncate(contacts[i].get_last_name()) << "|";
		std::cout << std::setw(width) << truncate(contacts[i].get_nickname()) << std::endl;
	}
}

void PhoneBook::print_index()
{
	int			index;
	std::string	str;
	
	std::cout << std::endl << "Enter the index of the contact: " << std::endl;
	std::getline(std::cin, str);
	index = std::atoi(str.c_str());
	while (index <= 0 || index > saved_contacts)
	{
		std::cout << "\033[31m" << "\nPlease enter a valid Contact index!" << "\033[0m" << std::endl << std::endl;
		std::cout << "Enter the index of the contact: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cout << std::endl << "CTRL-D Pressed. Exiting Phonebook!" << std::endl;
			std::exit(0);
		}
		index = std::atoi(str.c_str());
	}
    std::cout << "\n" << std::setw(20) << std::left << "First Name:" 
              << contacts[index - 1].get_first_name() << std::endl;
    std::cout << std::setw(20) << std::left << "Last Name:"
              << contacts[index - 1].get_last_name() << std::endl;
    std::cout << std::setw(20) << std::left << "Nickname:" 
              << contacts[index - 1].get_nickname() << std::endl;
    std::cout << std::setw(20) << std::left << "Darkest Secret:" 
              << contacts[index - 1].get_darkest_secret() << std::endl;
    std::cout << std::setw(20) << std::left << "Phone Number:" 
              << contacts[index - 1].get_number() << std::endl << std::endl;
}

void PhoneBook::search()
{
	if (saved_contacts == 0)
	{
		std::cout << "\033[31m" << "There is no contacts here yet. Returning to Menu...\n" << "\033[0m" << std::endl;
		return;
	}
	print_all_contacts();
	if (std::cin.eof())
	{
		std::cout << std::endl << "CTRL-D Pressed. Exiting Phonebook!" << std::endl;
		std::exit(0);
	}
	print_index();
}
