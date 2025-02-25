#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

static int count = 0;

class Base
{
    public:
        Base(){std::cout << "Constructing base!" << std::endl;}
        virtual ~Base(){std::cout << "Desstructing base!" << std::endl;}
};

class Derived : public Base{
    public:
        Derived(){std::cout << "Constructing derived!" << std::endl;}
        ~Derived(){std::cout << "Destructing derived!" << std::endl;}
};

int main (int argc, char** argv)
{
    Derived *d = new Derived();
    Base *b = d;
    delete b;
    return EXIT_SUCCESS;
}