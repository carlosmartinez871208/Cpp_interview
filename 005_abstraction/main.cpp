#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

class Abstraction
{
    private:
        int a,b;
    public:
        void set (int x, int y)
        {
            a=x;
            b=y;
        }
        void display ()
        {
            std::cout << "Value of a: " << a << std::endl;
            std::cout << "Value of b: " << b << std::endl;
        }
};

int main (int argc, char** argv)
{
    Abstraction obj;
    obj.set(5,4);
    obj.display();
    return EXIT_SUCCESS;
}