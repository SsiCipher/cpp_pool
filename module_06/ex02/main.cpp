#include "classes.hpp"

Base *generate(void)
{
	int n = time(0) % 3;

	if (n == 0)
		return (new A());
	else if (n == 1)
		return (new B());
	else if (n == 2)
		return (new C());
	return (NULL);
}

void identify(Base *p)
{
	A *a = dynamic_cast<A *>(p);
	if (a)
	{
		std::cout << "A" << std::endl;
		return;
	}
	B *b = dynamic_cast<B *>(p);
	if (b)
	{
		std::cout << "B" << std::endl;
		return;
	}
	C *c = dynamic_cast<C *>(p);
	if (c)
	{
		std::cout << "C" << std::endl;
		return;
	}
	std::cout << "Invalid Class Type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (const std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (const std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cout << "Invalid Class Type" << std::endl;
			}
		}
	}
}

int main(void)
{
	Base invalid;
	Base *random = generate();

	identify(invalid);
	identify(&invalid);
	identify(random);
	identify(*random);
	return (0);
}
