#include "Clap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Clap::Clap()
{
}

Clap::Clap( const Clap & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Clap::~Clap()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Clap &				Clap::operator=( Clap const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Clap const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}
