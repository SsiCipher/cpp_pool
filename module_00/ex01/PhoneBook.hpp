#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
	private:
		int		_contacts_count;
		Contact	_contacts[8];
		void	_print_field(std::string &value, size_t limit);
		void	_display_contacts(void);

	public:
		PhoneBook(void);
		void	add_contact(Contact &obj);
		void	search_by_index(void);
};
