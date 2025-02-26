#include <iostream>

#ifndef EXIT_SUCCESS
 #define EXITS_SUCESS 0u
#endif

class SmartPtr
{
    int* ptr;

    public:
        explicit SmartPtr(int* p = nullptr){ptr=p;}

        ~SmartPtr() {delete(ptr);}

        int& operator*() {return *ptr;}
};

int main (int argc, char** argv)
{
    SmartPtr ptr(new int());
    *ptr = 20;
    std::cout << *ptr << std::endl;
    return EXIT_SUCCESS;
}
