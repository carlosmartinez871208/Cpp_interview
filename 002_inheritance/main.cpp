#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

/* This is the base class */
class base
{
    public:
        int id_base;
        void printB(){std::cout << "Base ID: " << id_base << std::endl;}
};

/* This is the derived class from base: this inherits behaviors and data from base public. */
class derived : public base
{
    public:
        int id_derived;
        void printD(){std::cout << "Derived ID: " << id_derived << std::endl;}
};

int main (int argc, char** argv)
{
    derived object; /* derived class instanciation */
    object.id_base = 2; /* Access to base class members */
    object.printB();
    object.id_derived = 4; /* Access to base class members */
    object.printD();
    return EXIT_SUCCESS;
}