#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

class myClass
{
    public:          /* Access specifier. */
        int var;     /* Data member. */
        void print() /* Methods to access data members. */
        {
            std::cout << "Hello " << var << std::endl;
        }
};  

int main (int argc, char** argv)
{
    myClass myObject;
    myObject.var = 10;
    myObject.print();
    return EXIT_SUCCESS;
}
