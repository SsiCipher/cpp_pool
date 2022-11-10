#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
	private:
		int		_contacts_count;
		Contact	_contacts[8];
		void	_print_field(std::string &value, size_t limit);

	public:
		PhoneBook(void);
		void	add_contact(Contact &obj);
		void	display_contacts(void);
		void	search_by_index(void);
};
