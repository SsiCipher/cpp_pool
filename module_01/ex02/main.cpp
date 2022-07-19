#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "---- Addresses ----\n";

	std::cout << "The memory address of the string variable is: " << &str << "\n";
	std::cout << "The memory address held by stringPTR is: " << stringPTR << "\n";
	std::cout << "The memory address held by stringREF is: " << &stringREF << "\n";

	std::cout << "---- Values ----\n";

	std::cout << "The value of the string variable is: " << str << "\n";
	std::cout << "The value pointed to by stringPTR is: " << *stringPTR << "\n";
	std::cout << "The value pointed to by stringREF is: " << stringREF << "\n";

	return (0);
}
