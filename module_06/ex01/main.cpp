#include <iostream>

struct Data
{
	int n;
	char c;
	std::string s;
};

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data d;

	d.n = 654;
	d.c = 'a';
	d.s = "Hello world";
	uintptr_t ui = serialize(&d);
	std::cout << "Hex: " << &d << ", uint: " << ui << std::endl;

	std::cout << deserialize(ui)->n << std::endl;
	std::cout << deserialize(ui)->c << std::endl;
	std::cout << deserialize(ui)->s << std::endl;
	return (0);
}
