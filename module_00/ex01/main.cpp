#include "PhoneBook.hpp"

Contact read_contact()
{
	Contact c;

	std::cout << "Enter first_name: ";
	std::cin >> c.first_name;
	std::cout << "Enter last_name: ";
	std::cin >> c.last_name;
	std::cout << "Enter nickname: ";
	std::cin >> c.nickname;
	std::cout << "Enter phone_number: ";
	std::cin >> c.phone_number;
	std::cout << "Enter darkest_secret: ";
	std::cin >> c.darkest_secret;

	return (c);
}

int main(void)
{
	std::string	cmd;
	PhoneBook	book;

	while (true)
	{
		std::cout << "Enter a command (ADD|SEARCH|EXIT): ";
		std::cin >> cmd;
		if (cmd == "ADD")
		{
			Contact c = read_contact();
			book.add_contact(c);
		}
		else if (cmd == "SEARCH")
			book.search_by_index();
		else if (cmd == "EXIT")
			return (0);
		std::cout << "\n";
	}

	return (0);
}
