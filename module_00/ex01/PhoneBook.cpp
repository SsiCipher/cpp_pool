#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_contacts_count = 0;
}

void	PhoneBook::add_contact(Contact &obj)
{
	int curr_i = this->_contacts_count % 8;

	this->_contacts[curr_i].first_name = obj.first_name;
	this->_contacts[curr_i].last_name = obj.last_name;
	this->_contacts[curr_i].nickname = obj.nickname;
	this->_contacts[curr_i].phone_number = obj.phone_number;
	this->_contacts[curr_i].darkest_secret = obj.darkest_secret;

	this->_contacts_count += 1;
}

void	PhoneBook::_print_field(std::string &value, size_t limit)
{
	int spaces = value.size() < limit ? limit - (value.size() % limit) : 0;
	if (value.size() > limit)
		std::cout << std::string(spaces, ' ') << value.substr(0, limit - 1) << ".";
	else
		std::cout << std::string(spaces, ' ') << value.substr(0, limit);
}

void	PhoneBook::_display_contacts(void)
{
	if (this->_contacts_count == 0)
		std::cout << "|        The phonebook is empty        |\n";
	for (int i = 0; i < this->_contacts_count; i++)
	{
		Contact curr = this->_contacts[i];
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|";
		this->_print_field(curr.first_name, 10);
		std::cout << "|";
		this->_print_field(curr.last_name, 10);
		std::cout << "|";
		this->_print_field(curr.nickname, 10);
		std::cout << "|" << "\n";
	}
}

void	PhoneBook::search_by_index(void)
{
	int index = -1;
	
	this->_display_contacts();
	while (index < 0 || index > this->_contacts_count)
	{
		std::cout << "Enter index: ";
		std::cin >> index;
		if (index < 0 || index > this->_contacts_count)
			std::cout << "No contacts found at index: " << index << "\n";
	}

	std::cout << "Contact at index: " << index << "\n";
	Contact &curr = this->_contacts[index];
	std::cout << "|" << std::setw(20) << index;
	std::cout << "|";
	this->_print_field(curr.first_name, 20);
	std::cout << "|";
	this->_print_field(curr.last_name, 20);
	std::cout << "|";
	this->_print_field(curr.nickname, 20);
	std::cout << "|";
	this->_print_field(curr.phone_number, 20);
	std::cout << "|";
	this->_print_field(curr.darkest_secret, 20);
	std::cout << "|" << "\n";
}
