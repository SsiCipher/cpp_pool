#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		~WrongCat(void);
		WrongCat(const WrongCat &obj);
		WrongCat &operator=(const WrongCat &obj);

		void	makeSound(void) const;
};

#endif
