#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

class Base
{
    private:
        int private_variable;
    
    protected:
        int protected_variable;
    
    public:
        Base()
        {
            private_variable = 10;
            protected_variable = 99;
        }

        friend void friendFunction (Base& obj);
};

void friendFunction(Base& obj);
/**************************************************************************************/
class A;

class anotherClass
{
    public:
        void memberFunction(A& obj);
};

class A
{
    private:
        int private_variable;

    protected:
        int protected_variable;

    public:
        A()
        {
            private_variable = 10;
            protected_variable = 99;
        }

        friend void anotherClass::memberFunction(A&);
};

void anotherClass::memberFunction(A& obj)
{
    std::cout << "Private variable = " << obj.private_variable << std::endl;
    std::cout << "Protected variable = " << obj.protected_variable << std::endl;
}

int main (int argc, char** argv)
{
    Base obj1;
    friendFunction(obj1);
    A obj2;
    anotherClass obj3;
    obj3.memberFunction(obj2);
    return EXIT_SUCCESS;
}

void friendFunction(Base& obj)
{
    std::cout << "Private variable = " << obj.private_variable << std::endl;
    std::cout << "Protected variable = " << obj.protected_variable << std::endl;
}