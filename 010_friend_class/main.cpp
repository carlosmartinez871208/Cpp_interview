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

        friend class F;
};

class F
{
    public:
        void display(Base& base)
        {
            std::cout << "Private variable value = " << base.private_variable << std::endl;
            std::cout << "Protected variable value = " << base.protected_variable << std::endl;
        }
};

int main (int argc, char** argv)
{
    Base base;
    F f;
    f.display(base);
    return EXIT_SUCCESS;
}