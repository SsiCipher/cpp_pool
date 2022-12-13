#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "\n------ Normal tests ------\n" << std::endl;

	const Animal* meta = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();

	std::cout << d->getType() << std::endl;
	std::cout << c->getType() << std::endl;
	c->makeSound();
	d->makeSound();
	meta->makeSound();

	delete meta;
	delete d;
	delete c;

	std::cout << "\n------ Wrong tests ------\n" << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	wrongMeta->makeSound();
	wrongCat->makeSound();
	
	delete wrongMeta;
	delete wrongCat;

	return 0;
}
