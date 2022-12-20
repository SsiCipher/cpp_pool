#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	//Animal *animals[10];
	Cat a;
	{
		std::cout << "www" << std::endl;
		Cat b = a;
	}
	// for (int i = 0; i < 5; i++)
	// 	animals[i] = new Dog();
	// for (int i = 5; i < 10; i++)
	// 	animals[i] = new Cat();

	// for (int i = 0; i < 10; i++)
	// {
	// 	animals[i]->makeSound();
	// 	delete animals[i];
	// }

	return 0;
}
