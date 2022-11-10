#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_contacts_count = 0;
}

void	PhoneBook::add_contact(Contact &new_contact)
{
	int curr_i = this->_contacts_count % 8;

	if (new_contact.isEmpty())
		return;
	this->_contacts[curr_i].first_name = new_contact.first_name;
	this->_contacts[curr_i].last_name = new_contact.last_name;
	this->_contacts[curr_i].nickname = new_contact.nickname;
	this->_contacts[curr_i].phone_number = new_contact.phone_number;
	this->_contacts[curr_i].darkest_secret = new_contact.darkest_secret;
	this->_contacts_count += 1;
}

void	PhoneBook::_print_field(std::string &value, size_t limit)
{
	int empty_spaces_count;

	empty_spaces_count = value.length() < limit ? limit - (value.length() % limit) : 0;
	if (value.size() > limit)
		std::cout << std::string(empty_spaces_count, ' ') << value.substr(0, limit - 1) << ".";
	else
		std::cout << std::string(empty_spaces_count, ' ') << value.substr(0, limit);
}

void	PhoneBook::display_contacts(void)
{
	Contact	current_contact;

	if (this->_contacts_count == 0)
	{
		std::cout << "--------------------------------------------\n";
		std::cout << "|          The phonebook is empty          |\n";
		std::cout << "--------------------------------------------\n";
	}
	for (int i = 0; i < this->_contacts_count; i++)
	{
		current_contact = this->_contacts[i];
		std::cout << "---------------------------------------------" << "\n";
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|";
		this->_print_field(current_contact.first_name, 10);
		std::cout << "|";
		this->_print_field(current_contact.last_name, 10);
		std::cout << "|";
		this->_print_field(current_contact.nickname, 10);
		std::cout << "|" << "\n";
		std::cout << "---------------------------------------------" << "\n";
	}
}

void	PhoneBook::search_by_index(void)
{
	int index = -1;

	if (this->_contacts_count == 0)
		return;
	while (!std::cin.eof() && (index < 0 || index > this->_contacts_count - 1))
	{
		std::cout << "Enter a contact index: ";
		std::cin >> index;
		if (index < 0 || index > this->_contacts_count - 1)
			std::cout << "No contacts found at index: " << index << "\n";
	}
	if (index != -1)
	{
		Contact &curr = this->_contacts[index];
		std::cout << "\n";
		std::cout << "Index: " << index << "\n";
		std::cout << "first_name: " << curr.first_name << "\n";
		std::cout << "last_name: " << curr.last_name << "\n";
		std::cout << "nickname: " << curr.nickname << "\n";
		std::cout << "phone_number: " << curr.phone_number << "\n";
		std::cout << "darkest_secret: " << curr.darkest_secret << "\n";
	}
}
