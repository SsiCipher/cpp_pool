#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(void);
		AMateria(std::string const & type);
		virtual ~AMateria(void);
		AMateria(const AMateria &obj);
		AMateria &operator=(const AMateria &obj);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
