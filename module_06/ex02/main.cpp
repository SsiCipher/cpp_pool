#include <iostream>

class Base
{
    public:
        virtual ~Base(void) {};
};

class A: public Base
{
	public:
		~A() {};
};

class B: public Base
{
	public:
		~B() {};
};

class C: public Base
{
	public:
		~C() {};
};

Base* generate(void)
{
    // generate random int
    // if 1 <= n < 3 => return (new A())
    // if 3 <= n < 6 => return (new B())
    // if 3 <= n < 9 => return (new C())
    return (new A());
}

void identify(Base* p)
{
    A *a = dynamic_cast<A *>(p);
    if (a)
    {
        std::cout << "A" << std::endl;
        return ;
    }
    B* b = dynamic_cast<B *>(p);
    if (b)
    {
        std::cout << "B" << std::endl;
        return ;
    }
    C *c = dynamic_cast<C *>(p);
    if (c)
    {
        std::cout << "C" << std::endl;
        return ;
    }
}

void identify(Base& p)
{
    try
    {
        dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {
        try
        {
            dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << "C" << std::endl;
        }
        
    }
}

int main(void)
{
    return (0);
}
