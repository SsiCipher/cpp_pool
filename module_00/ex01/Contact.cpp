#include "Contact.hpp"

bool    Contact::isEmpty()
{
    return (
        this->first_name.empty()
		|| this->last_name.empty()
		|| this->nickname.empty()
		|| this->phone_number.empty()
		|| this->darkest_secret.empty()
    );
}
