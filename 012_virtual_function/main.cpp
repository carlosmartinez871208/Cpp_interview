#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

class Base
{
    public:
        virtual void print(){std::cout << "Print base class" << std::endl;}
        void show(){std::cout << "Show base class" << std::endl;}
};

class Derived : public Base
{
    public:
        void print(){std::cout << "Print Derived class" << std::endl;}
        void show(){std::cout << "Show Derived class" << std::endl;}
};

int main (int argc, char** argv)
{
    Base* bptr;
    Derived d;
    bptr = &d;
    /* Virtual function, binded at runtime */
    bptr->print();
    /* Non virtual function, binded at compile time */
    bptr->show();
    return EXIT_SUCCESS;
}
