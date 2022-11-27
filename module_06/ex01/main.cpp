#include <iostream>

struct Data
{
	int	n;
};

uintptr_t serialize(Data* ptr)
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
	uintptr_t ui = serialize(&d);
	std::cout << deserialize(ui)->n << std::endl;
	return (0);
}
