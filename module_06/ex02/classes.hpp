#include <iostream>

class Base
{
	public:
		virtual ~Base(void) {};
};

class A : public Base
{
	public:
		~A() {};
};

class B : public Base
{
	public:
		~B() {};
};

class C : public Base
{
	public:
		~C() {};
};

void identify(Base *p);
void identify(Base &p);
