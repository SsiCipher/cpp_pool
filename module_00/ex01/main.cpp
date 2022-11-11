#include "PhoneBook.hpp"

void read_contact(Contact &contact)
{
	std::cout << "Enter first_name: ";
	std::getline(std::cin, contact.first_name);
	std::cout << "Enter last_name: ";
	std::getline(std::cin, contact.last_name);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, contact.nickname);
	std::cout << "Enter phone_number: ";
	std::getline(std::cin, contact.phone_number);
	std::cout << "Enter darkest_secret: ";
	std::getline(std::cin, contact.darkest_secret);
}

int main(void)
{
	std::string	cmd;
	PhoneBook	book;
	Contact		new_contact;

	std::cout << "Enter a command (ADD|SEARCH|EXIT): ";
	while (std::getline(std::cin, cmd))
	{
		std::cout << cmd;
		std::cout << "\n";
		if (cmd == "ADD")
		{
			read_contact(new_contact);
			book.add_contact(new_contact);
		}
		else if (cmd == "SEARCH")
		{
			book.display_contacts();
			book.search_by_index();
		}
		else if (cmd == "EXIT")
			break;
		std::cout << "\nEnter a command (ADD|SEARCH|EXIT): ";
	}
	return (0);
}
