#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog: public Animal
{
	private:
		Brain	*_brain;

	public:
		Dog(void);
		virtual ~Dog(void);
		Dog(const Dog &obj);
		Dog &operator=(const Dog &obj);

		void	makeSound(void) const;
};

#endif
